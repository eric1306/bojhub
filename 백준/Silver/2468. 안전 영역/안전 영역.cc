// Authored by: prid1306
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
#define x first
#define y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using pii = pair<int,int>;
int n;
int board[101][101];
int _min = 0x3fffffff;
int _max = -1;
inline bool OOB(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= n;
}
int main(){
    FASTIO;
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        cin>>board[i][j];
        if(_min > board[i][j]) _min = board[i][j];
        if(_max < board[i][j]) _max = board[i][j];
    }
    int ans = 1;
    //i값 이하인 영역은 모두 침수라고 가정
    for(int i=_min; i<=_max;i++)
    {
        int curArea = 0;
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(board[j][k] <= i || visit[j][k]) continue;
                visit[j][k] = true;
                queue<pii> q;
                q.emplace(j, k);
                while(!q.empty())
                {
                    auto p = q.front(); q.pop();
                    for(int idx = 0; idx < 4; idx++)
                    {
                        int nx = p.x + dx[idx];
                        int ny = p.y + dy[idx];
                        if(OOB(nx, ny)) continue;
                        if(visit[nx][ny]) continue;
                        if(board[nx][ny] <= i) continue;
                        q.emplace(nx, ny);
                        visit[nx][ny] = true;
                    }
                }
                curArea++;
            }
        }
        if(curArea > ans) ans = curArea;
    }
    cout<<ans;
}