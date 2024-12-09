#include <iostream>
#include <utility>
#include <queue>

#define x first
#define y second

using namespace std;
int dist[100002];
int n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    queue<int> q;
    fill(dist, dist+100001,-1);
    
    q.push(n);
    dist[n] = 0;
    while(dist[k] == -1){
        int p = q.front();q.pop();
        for(int nxt : {p-1, p+1, p*2}){
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[p]+1;
            q.push(nxt);
        }
    }

    cout<<dist[k];
}