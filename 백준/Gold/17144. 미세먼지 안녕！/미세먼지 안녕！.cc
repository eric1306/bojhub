// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int a[51][51];
int r,c,t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
pair<int,int> pos{0, 0};
void MoveFineDust()
{
    //위쪽
    int Up = pos.first;
    for(int i = Up - 1; i > 0; --i)
    {
        a[i][0] = a[i-1][0];
    }
    for(int i = 0; i < c-1; ++i){
        a[0][i] = a[0][i + 1];
    }
    for(int i= 0; i < Up; ++i)
    {
        a[i][c - 1] = a[i + 1][c - 1];
    }
    for(int i = c-1; i > 0; --i){
        a[Up][i] = a[Up][i-1];
    }
    a[Up][1] = 0;

    //아래쪽
    int Down = pos.second;
    for(int i = Down + 1; i < r-1; ++i)
    {
        a[i][0] = a[i+1][0];
    }
    for(int i = 0; i < c-1; ++i){
        a[r-1][i] = a[r-1][i + 1];
    }
    for(int i= r-1; i > Down; --i)
    {
        a[i][c - 1] = a[i - 1][c - 1];
    }
    for(int i = c-1; i > 0; --i){
        a[Down][i] = a[Down][i-1];
    }
    a[Down][1] = 0;
}

void DiffusionFineDust()
{
    //기존 배열 캐싱하는 배열 필요
    int copya[51][51];
    int cacheDDust[51][51];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++){
        copya[i][j] = cacheDDust[i][j] = 0;

    }
    for(int i=0;i<r;i++) for(int j=0;j<c;j++)
    {
        copya[i][j] = a[i][j];
    }
    //각 칸이 확산 될 때의 값 얻기
    for(int i=0;i<r;i++) for(int j=0;j<c;j++)
    {
        if(a[i][j] == 0) continue;
        int value = copya[i][j] / 5;
        if(value == 0) continue;

        for(int dir=0;dir<4;dir++)
        {
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue; //OOB
            if(a[nx][ny] == -1) continue;
            copya[i][j] -= value;
            cacheDDust[nx][ny] += value;
            
        }
    }
    //그 값을 기존 값에 갱신
    for(int i=0;i<r;i++) for(int j=0;j<c;j++){
        a[i][j] = (copya[i][j] + cacheDDust[i][j]);
    }
}

int main(){
    FASTIO;
    cin>>r>>c>>t;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++)
    {
        cin>>a[i][j];
        if(a[i][j] == -1 && pos.first == 0)
        {
            pos.first = i;
        }
        else if(a[i][j] == -1 && pos.second == 0)
        {
            pos.second = i;
        }
        else
        {
            continue;
        }
    }
    while(t--)
    {
        DiffusionFineDust();
        MoveFineDust();
    }

    int ans = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j] > 0)
                ans += a[i][j];
        }
    }
    cout<<ans<<'\n';
}