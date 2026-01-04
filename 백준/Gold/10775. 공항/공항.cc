// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int g,p;
int parent[100'001];
int find(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void uni(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u!=v) parent[u] = v;
}
int main(){
    FASTIO;
    cin>>g>>p;
    for(int i=0;i<=g;i++){
        parent[i] = i;
    }
    int ans = 0; 
    for(int i=0;i<p;i++)
    {
        int gate;cin>>gate;
        int root = find(gate);
        if(root == 0) break;
        uni(root, root - 1);
        ans++;
    }
    cout<<ans;
}