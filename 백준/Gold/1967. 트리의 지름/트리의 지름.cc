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
vector<pii> adj[10'001];
int DFS(int st, int value)
{
    int s=0,tmp;
    for(auto nxt : adj[st])
    {
        tmp = DFS(nxt.x, nxt.y + value) + nxt.y;
        ans = max(ans, s + tmp);
        s = max(s, tmp);
    }
    return s;
}
int main(){
    FASTIO;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int p,c,v; cin>>p>>c>>v;
        adj[p].push_back(make_pair(c, v));
    }
    //for문을 돌면서, 각 정점들끼리의 거리를 보관하는 배열 하나 생성
    DFS(1, 0);
    cout<<ans<<'\n';
}