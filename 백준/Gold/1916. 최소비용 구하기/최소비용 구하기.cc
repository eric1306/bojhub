// Authored by: prid1306
#include <iostream>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,m,st, dest;
int bus[1001][1001];
long long dist[1001];
using pii = pair<int,int>;
int main(){
    FASTIO;
    cin>>n>>m;
    fill(dist, dist + 1001, 0x3fffffff);
    for(int i=0;i<1001;i++){
        fill(bus[i], bus[i] + 1001, -1);
    }
    for(int i=0;i<m;i++){
        int x,y,value;cin>>x>>y>>value;
        if(bus[x][y]!=-1) bus[x][y] = min(bus[x][y], value);
        else bus[x][y] = value;
    }
    cin>>st>>dest;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});
    dist[st] = 0;
    while(!pq.empty())
    {
        auto p = pq.top();pq.pop();
        for(int i=1;i<=n;i++){
            if(bus[p.second][i] == -1) continue;
            if(dist[i] <= bus[p.second][i] + p.first) continue;
            dist[i] = p.first + bus[p.second][i];
            pq.push({dist[i], i});
            //cout<<p.second<<"->"<<i<<' '<<p.first + dist[i]<<'\n';
        }
    }
    cout<<dist[dest];
}