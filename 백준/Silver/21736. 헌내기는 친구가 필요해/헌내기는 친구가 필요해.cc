// Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

#define x first
#define y second
using pii = pair<int,int>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string a[601];
bool visit[601][601];
int n,m;
pii doyeonPos;

bool OOB(int x, int y)
{
    return (x < 0 || x >= n || y < 0 || y >= m);
}
int main(){
    FASTIO;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<m;j++)
        {
            if(a[i][j] == 'I'){
                doyeonPos = {i, j};
            }
        }
    }
    queue<pii> q;
    q.push(doyeonPos);
    visit[doyeonPos.x][doyeonPos.y] = true;
    int ans = 0;
    while(!q.empty())
    {
        auto p = q.front(); q.pop();
        //cout<<p.x<<' '<<p.y<<'\n';
        for(int i=0;i<4;i++)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(OOB(nx, ny)) continue;
            if(visit[nx][ny]||a[nx][ny] == 'X') continue;
            if(a[nx][ny] == 'P') ans++;
            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    if(ans == 0) cout<<"TT";
    else cout<<ans;
}