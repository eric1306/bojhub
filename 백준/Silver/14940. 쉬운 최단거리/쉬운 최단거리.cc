// Authored by: prid1306
#include <iostream>
#include <queue>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using pii = pair<int,int>;
#define x first
#define y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m;
pii stPos;
int board[1002][1002];
int ans[1002][1002];

bool OOB(int x, int y)
{
    return (x < 0 || x >= n || y < 0 || y >= m);
}

int main(){
    FASTIO;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        fill(ans[i], ans[i] + m, -1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j] == 2){
                stPos = {i, j};
            }else if(board[i][j] == 0){
                ans[i][j] = 0;
            }
        }
    }
    queue<pii> q;
    q.push(stPos);
    ans[stPos.x][stPos.y] = 0;
    while(!q.empty())
    {
        auto p = q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(OOB(nx, ny)) continue;
            if(ans[nx][ny] != -1 || board[nx][ny] == 0) continue;
            ans[nx][ny] = ans[p.x][p.y] + 1;
            q.push({nx, ny});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}