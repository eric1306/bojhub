// Authored by: prid1306
#include <iostream>
#include <queue>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using tiii = tuple<int,int,int>;
#define x first
#define y second
int r,c;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[21];
bool isused[27];
int ans = 1;
int getIdx(char c) { return static_cast<int>(c - 'A');}
bool OOB(int x, int y) { return (x < 0 || x >= r || y < 0 || y >= c);}
void BT(int x, int y, int value)
{
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(OOB(nx, ny)) continue;
        if(isused[getIdx(board[nx][ny])]) continue;
        isused[getIdx(board[nx][ny])] = true;
        ans = max(ans, value + 1);
        BT(nx, ny, value + 1);
        isused[getIdx(board[nx][ny])] = false;
    }
}
int main(){
    FASTIO;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        cin>>board[i];
    }
    isused[getIdx(board[0][0])] = true;
    BT(0, 0, 1);
    cout<<ans<<'\n';
}