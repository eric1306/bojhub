// Authored by: prid1306
// BOJ 13549
#include <iostream>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
const int MAX = 200'002;
int dist[MAX];
int main(){
    FASTIO;
    int n,k;cin>>n>>k;
    fill(dist, dist + MAX, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(dist[k]==-1){
        int cur = q.front();q.pop();
        //2배
        if(cur <100'000){
            int nxt = cur * 2;
            dist[nxt] = dist[cur];
            q.push(nxt);
        }
        for(int nxt : {cur - 1, cur + 1}){
            if(nxt < 0 || nxt > 100'000) continue;
            if(dist[nxt]!=-1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    cout<<dist[k]<<'\n';
}