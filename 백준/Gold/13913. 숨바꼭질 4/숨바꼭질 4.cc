// Authored by: prid1306
#include <iostream>
#include <queue>
#include <stack>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
const int MAX = 100'002;
int dist[MAX];
int p[MAX];
int main(){
    FASTIO;
    int n,k;cin>>n>>k;
    fill(dist, dist + MAX, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    p[n] = -1; //루트라는 표시
    while(dist[k] == -1){
        int cur = q.front();q.pop();
        for(int nxt : {cur + 1, cur - 1, cur * 2})
        {
            if(nxt < 0 || nxt > 100'000) continue;
            if(dist[nxt]!= -1) continue;
            dist[nxt] = dist[cur] + 1;
            p[nxt] = cur;
            q.push(nxt);
        }
    }
    int tmp = k;
    stack<int> s;
    while(tmp!=-1){
        s.push(tmp);
        tmp = p[tmp];
    }
    cout<<dist[k]<<'\n';
    while(!s.empty()){
        cout<<s.top()<<' ';s.pop();
    }
}