//Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> p(201,-1);

int find(int x)
{
    if(p[x] < 0)
        return x;
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>m;
    int elem;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>elem;
            if(elem)
                uni(i,j);
        }
    }
    int u,v;
    cin>>u;
    for(int i=1;i<m;i++)
    {
        cin>>v;
        if(find(u) == find(v))
        {
            u = v;
            continue;
        }
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
} 