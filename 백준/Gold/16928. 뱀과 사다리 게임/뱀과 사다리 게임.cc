// Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,m;

int main(){
    FASTIO;
    cin>>n>>m;
    vector<int> ladders(101, 0);
    vector<int> snakes(101, 0);
    for(int i=0;i<n;i++){
        int st,en; cin>>st>>en;
        ladders[st] = en;
    }
    for(int i=0;i<m;i++){
        int st,en;cin>>st>>en;
        snakes[st] = en;
    }
    vector<int> dist(101, 0);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty())
    {
        int p = q.front();q.pop();
        for(int i=1;i<7;++i)
        {
            int pos = p + i;
            if(pos > 100) continue;
            if(dist[pos]) continue;
            dist[pos] = dist[p] + 1;
            int tmp = pos;
            if(ladders[pos]){
                pos = ladders[pos];
            }
            else if(snakes[pos]){
                pos = snakes[pos];
            }
            if(dist[pos] == 0) 
                dist[pos] = dist[tmp];

            q.push(pos);
        }
    }
    cout<<dist[100];
}