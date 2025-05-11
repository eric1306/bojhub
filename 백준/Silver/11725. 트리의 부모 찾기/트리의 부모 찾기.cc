//Authored by: prid1306
#include <bits/stdc++.h>
using namespace std;
int p[100'002];
vector<int> adj[100'002];
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,l,r;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>l>>r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }

    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int cur = q.front();q.pop();
        for(int nxt : adj[cur])
        {
            if(p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
    for(int i=2;i<=n;i++)
    {
        cout<<p[i]<<'\n';
    }
} 