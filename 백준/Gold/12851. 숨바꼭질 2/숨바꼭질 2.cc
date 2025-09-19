// Authored by: prid1306
// BOJ 12851
#include <iostream>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
const int MAX = 100'002;
int dist[MAX];
int cnt[MAX];
int main(){
    FASTIO;
    int n,k;cin>>n>>k;
    fill(dist, dist+100002, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    cnt[n] = 1;
    while(!q.empty()){
        int cur = q.front();q.pop();
        for(int nxt : {cur - 1, cur + 1, cur*2})
        {
            if(nxt < 0 || nxt > 100'000) continue;
            if(dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                cnt[nxt] = cnt[cur];
                q.push(nxt);
            }else{
                if(dist[cur] + 1 == dist[nxt]) cnt[nxt] += cnt[cur];
            }
        }
    }
    cout<<dist[k]<<'\n'<<cnt[k];
}