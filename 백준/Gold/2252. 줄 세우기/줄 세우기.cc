//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,from,to;
vector<int> adj[32001];
int indegree[32001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>from>>to;
        adj[from].push_back(to);
        indegree[to]++;
    }
    queue<int> q;
    vector<int> result;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i] == 0) 
            q.push(i);
    }
    while(!q.empty())
    {
        int cur = q.front();q.pop();
        result.push_back(cur);
        for(int nxt : adj[cur])
        {
            indegree[nxt] --;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    }
    for(auto c : result) cout<<c<<' ';
}