//Authored by: prid1306
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> p(303, -1);
//Cost, 정점
tuple<int,int,int> edge[100005];
int find(int x)
{
    if(p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
    u = find(u);
    v=find(v);
    if(u == v) return false;
    if(p[v] < p[u]) swap(u,v);
    if(p[v] == p[u]) p[u]--;
    p[v] = u;
    return true;
}

int v,e;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>v;
    
    for(int i=1;i<=v;i++)
    {
        int weight;
        cin>>weight;
        edge[e++] = {weight, i, v+1};
    }
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            int cost;
            cin>>cost;
            if(i>=j) continue;
            edge[e++] = {cost, i, j};
        }
    }
    v++;
    sort(edge, edge+e);
    int cnt = 0;
    int ans = 0;
    for(int i=0;i<e;i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!uni(a, b)) continue;
        ans+=cost;
        cnt++;
        if(cnt == v-1) break;
    }
    cout<<ans;

}