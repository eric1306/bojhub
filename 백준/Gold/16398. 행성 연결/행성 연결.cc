//Authored by: prid1306
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> p(1001, -1);
int find(int x)
{
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
    u = find(u);v = find(v);
    if(u == v) return false;
    if(p[v] < p[u]) swap(u,v);
    if(p[v] == p[u]) p[u]--;
    p[v] = u;
    return true;
}
tuple<int,int,int> edge[500'001];
int n,a,b,cost;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int cnt = 0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        cin>>cost;
        if(i>=j) continue;
        edge[cnt++] = {cost, i, j};
    }
    int range = n * (n-1) / 2;
    sort(edge, edge + range);
    int idx = 0;
    unsigned long long ans = 0;
    cnt = 0;
    while(cnt < n-1)
    {
        tie(cost, a, b) = edge[idx++];
        if(uni(a,b))
        {
            ans+=cost;
            cnt++;
        }
    }
    cout<<ans<<'\n';
} 