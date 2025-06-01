//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define x first
#define y second
vector<pair<int,int>> adj[1005];
int v,e,st,en;
const int INF = 1e+9;

int d[1005];
int pre[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>v>>e;
    fill(d,d+1+v, INF);
    for(int i=1;i<=e;i++)
    {
        int a,b,cost;
        cin>>a>>b>>cost;
        adj[a].emplace_back(cost, b);
    }
    cin>>st>>en;
    d[st] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({d[st],st});
    while(!pq.empty())
    {
        auto cur = pq.top();pq.pop();
        if(d[cur.y]!=cur.x) continue;
        for(auto nxt : adj[cur.y])
        {
            if(d[cur.y] + nxt.x >= d[nxt.y]) continue;
            d[nxt.y] = d[cur.y] + nxt.x;
            pq.push({d[nxt.y], nxt.y});
            pre[nxt.y] = cur.y;
            
        }
    }
    cout<<d[en]<<'\n';
    vector<int> path;
    int cur = en;
    while(cur!=st){
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    reverse(path.begin(),path.end());
    cout<<path.size()<<'\n';
    for(auto x : path) cout<<x<<' ';
} 