//Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
#define PII pair<int,int>
int n,e,v1,v2;
const int MAX = 801;
vector<pair<int,int>> adj[MAX];
int d[MAX][MAX];
const int INF = 800'001;

void D(int st, int en){
    priority_queue<PII,vector<PII>, greater<PII>> pq;
    d[st][st] = 0;
    pq.push({d[st][st],st});
    while(!pq.empty())
    {
        auto [dist, cur] = pq.top();pq.pop();
        if(d[st][cur]!=dist) continue;
        for(auto nxt : adj[cur])
        {
            auto [ncur,ndist] = nxt;
            if(dist + ndist >= d[st][ncur]) continue;
            d[st][ncur] = dist + ndist;
            pq.push({d[st][ncur],ncur});
            //cout<<ncur<<' '<<d[st][ncur]<<'\n';
        }
    }
    //for(int i=1;i<=n;i++) cout<<d[st][i]<<' ';
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    for(int i=1;i<=n;i++){
        fill(d[i],d[i]+n+1,INF);
    }
    cin>>v1>>v2;
    //1->v1->v2->n의 다익스트라 경로 탐색해야함.
    D(1, v1);D(1,v2);D(v2,v1);D(v1,v2);D(v2,n);D(v1,n);
    if(d[1][v1] == INF || d[v1][v2] == INF || d[v2][n] == INF) cout<<-1;
    else{
        int ret = min(d[1][v1] + d[v1][v2] + d[v2][n], d[1][v2] + d[v2][v1] + d[v1][n]);
        cout<<ret;
    }
}