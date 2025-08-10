// Authored by: prid1306
// BOJ
#include <iostream>
#include <vector>
using namespace std;
vector<int> p(500'001, -1);
int find(int x){
    if(p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){
        return false;
    }
    if(p[v] < p[u])
        swap(u, v);
    if(p[v] == p[u])
        p[u]--;
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int cnt = 0;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(!uni(a,b)){
            cnt = i+1;
            break;
        }
    }
    cout<<cnt;
} 