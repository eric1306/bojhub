//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define x first
#define y second

int n,m;
vector<pair<int,int>> v[1001];

int findlen(int from, int to)
{
    queue<pair<int,int>> q;
    vector<bool> vis(n+1);
    q.emplace(from, 0);
    vis[from] = true;
    while(!q.empty())
    {
        auto [cur,dist] = q.front();q.pop();
        if(cur == to){
            return dist;
        }
        for(auto [node, nodeDist] : v[cur])
        {
            if(vis[node]) continue;
            vis[node] = true;
            q.emplace(node, dist + nodeDist);
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int from,to,len;
    for(int i=0;i<n-1;i++)
    {
        cin>>from>>to>>len;
        v[from].emplace_back(to,len);
        v[to].emplace_back(from,len);
    }
    while(m--)
    {
        cin>>from>>to;
        cout<<findlen(from, to)<<'\n';
    }
}