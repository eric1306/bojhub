// Authored by: prid1306
#include <iostream>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
#define x first
#define y second
using namespace std;
using pii = pair<int,int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m;
int a[101][101];
vector<pii> deleteList;
int CheeseNum;
int ans;
int main(){
    FASTIO;
    cin>>n>>m;
    //1. 입력 받기.
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        cin>>a[i][j];
        if(a[i][j] == 1) CheeseNum++;
    }
    while(CheeseNum > 0)
    {
        ans++;

        bool visit[101][101];
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) visit[i][j] = false;        
        //2. (0, 0)에서 BFS 시작해서 외부 빈칸과 내부 빈칸 구분 시키기
        queue<pii> q;
        q.push({0, 0});
        a[0][0] = 2;
        visit[0][0] = true;
        while(!q.empty())
        {
            auto p = q.front();q.pop();
            for(int i=0;i<4;i++){
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //OOB
                if(visit[nx][ny]) continue;
                if(a[nx][ny] == 1) continue;
                q.push({nx, ny});
                visit[nx][ny] = true;
                a[nx][ny] = 2;
            }
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(a[i][j] == 0) a[i][j] = -2;
        }
        //3. 이중 for문으로 상하좌우 보면서 삭제될 치즈 찾기
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(a[i][j] == 1)
            {
                int cnt = 0;
                for(int dir=0;dir<4;dir++)
                {
                    if(a[i + dx[dir]][j + dy[dir]] == 2)
                        cnt++;
                }
                if(cnt >= 2)
                deleteList.push_back({i, j});
            }
        }
        //4. 모아둔 치즈 삭제
        for(auto deleteElem : deleteList)
        {
            a[deleteElem.x][deleteElem.y] = 2;
            CheeseNum--;
        }
        deleteList.clear();
        // cout<<"----------\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<a[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        // cout<<CheeseNum<<'\n';
    }
    cout<<ans;
}