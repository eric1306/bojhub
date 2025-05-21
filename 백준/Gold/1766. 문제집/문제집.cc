//Authored by: prid1306
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int p1,p2;
vector<int> adj[32001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int> cnt(n+1,0);
    vector<bool> visit(n+1,false);
    for(int i=1;i<=m;i++)
    {
        cin>>p1>>p2;
        adj[p1].push_back(p2);
        cnt[p2]++;
        visit[p1]=true;visit[p2]=true;
    }
    vector<int> p;
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size() && cnt[i] == 0 || !visit[i]) 
        {
            p.push_back(i);
        }
    }
    sort(p.begin(),p.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto c : p)
    {
        pq.push(c);
    }
    while(!pq.empty())
    {
        int cur = pq.top();pq.pop();
        cout<<cur<<' ';
        for(int nxt : adj[cur])
        {
            cnt[nxt]--;
            if(cnt[nxt] == 0)
            {
                pq.push(nxt);
            }
        }
    }
} 