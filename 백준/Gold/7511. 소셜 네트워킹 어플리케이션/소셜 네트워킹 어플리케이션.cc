// Authored by: prid1306
// BOJ 7511
#include <iostream>
#include <vector>
using namespace std;

vector<int> p(1000001, -1);

int Find(int x){
    if(p[x] < 0)
        return x;
    return p[x] = Find(p[x]);
}

bool uni(int u, int v){
    u = Find(u);
    v = Find(v);
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
    int t;cin>>t;
    int cnt = 1;
    while(t--)
    {
        int n,k,m;cin>>n>>k;
        while(k--){
            int a,b;cin>>a>>b;
            uni(a, b);
        }
        cin>>m;
        cout<<"Scenario "<<cnt++<<":\n";
        while(m--){
            int a,b;cin>>a>>b;
            if(Find(a) == Find(b)) cout<<"1\n";
            else cout<<"0\n";
        }
        fill(p.begin(),p.end(),-1);
        if(t!=0)cout<<'\n';
    }   
} 