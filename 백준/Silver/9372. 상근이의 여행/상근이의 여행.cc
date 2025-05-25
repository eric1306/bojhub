//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int t,n,m,a,b;

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
    if(p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        fill(p.begin(),p.end(),-1);
        cin>>n>>m;
        vector<pair<int,int>> adj;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            adj.emplace_back(a,b);
        }
        int cnt = 0;
        for(auto elem : adj)
        {
            if(cnt < n-1)
            {
                if(uni(elem.first, elem.second))
                {
                    cnt++;
                }
            }
            else{
                break;
            }
        }
        cout<<cnt<<'\n';
    }
} 