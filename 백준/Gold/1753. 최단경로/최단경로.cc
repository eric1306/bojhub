//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define x first
#define y second
vector<pair<int,int>> adj[300'001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int v,e,k;
const int INF = 0x3f3f3f3f;
int d[20001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>v>>e;
    cin>>k;
    fill(d,d+1+v, INF);
    for(int i=1;i<=e;i++)
    {
        int a,b,cost;
        cin>>a>>b>>cost;
        adj[a].emplace_back(b, cost);
    }
    pq.push({0, k});d[k] = 0;
    while(!pq.empty())
    {
        auto cur = pq.top();pq.pop();
        if(d[cur.y]!=cur.x) continue;
        for(auto nxt : adj[cur.y])
        {
            if(cur.x + nxt.y < d[nxt.x])
            {
                d[nxt.x] = cur.x + nxt.y;
                pq.push({d[nxt.x], nxt.x});
            }
        }
    }
    for(int i=1;i<=v;i++){
        if(d[i] == INF) cout<<"INF\n";
        else cout<<d[i]<<'\n';
    }
} 