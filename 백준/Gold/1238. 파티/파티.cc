//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int n,m,x;
vector<pair<int,int>> adj[1001];
int d[1001][1001];
const int INF = 0x3f3f3f3f;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>x;
    while(m--){
        int a,b,cost;
        cin>>a>>b>>cost;
        adj[a].push_back({cost, b});
    }
    for(int i=1;i<=n;i++){
        fill(d[i],d[i]+1+n,INF);
    }
    for(int i=1;i<=n;i++){
        d[i][i] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({d[i][i],i});
        while(!pq.empty()){
            auto cur = pq.top();pq.pop();
            if(d[i][cur.Y]!=cur.X) continue;
            for(auto nxt : adj[cur.Y])
            {
                if(d[i][nxt.Y] <= d[i][cur.Y] + nxt.X) continue;
                d[i][nxt.Y] = d[i][cur.Y] + nxt.X;
                pq.push({d[i][nxt.Y], nxt.Y});
            }
        }
    }
    //여기까지 O(ElgE)
    //TODO: 왕복 거리 최대합 구하기
    int ans = -1;
    for(int i=1;i<=n;i++)
    {
        if(ans < d[i][x] + d[x][i]) ans = d[i][x] + d[x][i];
    }
    cout<<ans;

} 