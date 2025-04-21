//Authored by: prid1306
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

#define x first
#define y second
using namespace std;

int n,m,k;
int board[101][101];
bool visit[101][101];
vector<int> v;

int dx[4] = {1,0,-1,0};
int dy[4] = {0, 1, 0, -1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int st_r,st_c,en_r,en_c;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        cin>>st_r>>st_c>>en_r>>en_c;
        for(int i=st_r;i<en_r;i++)
        {
            for(int j=st_c;j<en_c;j++)
            {
                board[j][i] = 1;
                visit[j][i] = true;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visit[i][j])
            {
                int qsize = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                visit[i][j] = true;
                qsize++;
                while(!q.empty())
                {
                    pair<int,int> p = q.front();q.pop();
                    for(int idx = 0; idx < 4; idx++)
                    {
                        int nx = p.x + dx[idx];
                        int ny = p.y + dy[idx];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(visit[nx][ny]) continue;
                        q.push({nx,ny});
                        visit[nx][ny] = true;
                        qsize++;
                    }
                }
                v.push_back(qsize);
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
    sort(v.begin(),v.end());
    for(auto c : v) cout<<c<<' ';
}