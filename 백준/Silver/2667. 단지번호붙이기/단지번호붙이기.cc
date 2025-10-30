// Authored by: prid1306
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

#define x first
#define y second
using pii = pair<int,int>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
string board[26];
bool visit[26][26];
vector<int> ans;

bool OOB(int x, int y)
{
    return (x < 0 || x >= n || y < 0 || y >= n);
}

int main(){
    FASTIO;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>board[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j] == '0' || visit[i][j]) continue; //방문했었거나, 0이라면 스킵
            int count = 1;
            queue<pii> q;
            q.push({i, j});
            visit[i][j] = true;
            while(!q.empty())
            {
                auto p = q.front();q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx = p.x + dx[i];
                    int ny = p.y + dy[i];
                    if(OOB(nx, ny)) continue;
                    if(visit[nx][ny] || board[nx][ny] == '0') continue;
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                    count++;
                }
            }
            ans.push_back(count);
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<'\n';
    for(auto elem : ans) cout<<elem<<'\n';
}