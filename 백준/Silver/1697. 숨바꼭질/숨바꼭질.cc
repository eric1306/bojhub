#include <iostream>
#include <utility>
#include <queue>

#define x first
#define y second

using namespace std;

int n,k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dist[100001];
    fill(dist,dist+100001,-1);
    cin>>n>>k;
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(dist[k]==-1){
        int cur = q.front();
        q.pop();
        for(int i: {cur-1,cur+1,cur*2}){
            if(i < 0 || i > 100000) continue;
            if(dist[i]!=-1) continue;
            q.push(i);
            dist[i] = dist[cur]+1;
        }
    }
    cout<<dist[k];
}