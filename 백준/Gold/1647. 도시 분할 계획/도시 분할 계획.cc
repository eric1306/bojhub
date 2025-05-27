//Authored by: prid1306
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,a,b,cost;

vector<int> p(100002, -1);
vector<tuple<int,int,int>> input;
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
    if(p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>cost;
        input.emplace_back(cost, a, b);
    }
    sort(input.begin(),input.end());
    long ans = 0;
    int maxValue = 0;
    int cnt = 0;
    for(auto v : input)
    {
        tie(cost, a, b) = v;
        if(uni(a, b))
        {
            ans+=cost;
            cnt++;
            if(maxValue < cost) maxValue = cost;
        }
        if(cnt == n-1) break;
    }
    cout<<ans - maxValue;
}