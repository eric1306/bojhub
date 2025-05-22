//Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int type, a, b;
vector<int> p(1'000'001, -1);

int find(int x)
{
    if(p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
        return false;
    if(p[v] < p[u])
        swap(u,v);
    if(p[v] == p[u])
        p[u]--;
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>type>>a>>b;
        switch (type)
        {
        case 0:
            uni(a, b);
            break;
        case 1:
            if(find(a) == find(b))
                cout<<"YES\n";
            else
                cout<<"NO\n";
            break;
        }
    }
} 