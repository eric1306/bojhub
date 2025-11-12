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
void DFS(int st, int value, int parent)
{
    for(auto nxt : adj[st])
    {
        if(nxt.x == parent) continue; //부모일경우 무시
        int newValue = value + nxt.y;
        ans = max(ans, newValue);
        DFS(nxt.x, newValue, st);
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
        DFS(i, 0, -1);
    }
    cout<<ans<<'\n';
}