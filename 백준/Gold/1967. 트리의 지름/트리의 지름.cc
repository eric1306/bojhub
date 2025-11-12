// Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using pii = pair<int,int>;
#define x first
#define y second
int n;
int ans = 0;
bool visited[10'001];
vector<pii> adj[10'001];
void DFS(int st, int value)
{
    for(auto nxt : adj[st])
    {
        if(visited[nxt.x]) continue;
        int newValue = value + nxt.y;
        ans = max(ans, newValue);
        visited[nxt.x] = true;
        DFS(nxt.x, newValue);
        visited[nxt.x] = false;
    }
}
int main(){
    FASTIO;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int p,c,v; cin>>p>>c>>v;
        adj[p].push_back(make_pair(c, v));
        adj[c].push_back(make_pair(p, v));
    }
    //for문을 돌면서, 각 정점들끼리의 거리를 보관하는 배열 하나 생성
    for(int i=1;i<=n;i++){
        fill(visited + 1, visited + n + 1, false);
        visited[i] = true;
        DFS(i, 0);
    }
    cout<<ans<<'\n';
}