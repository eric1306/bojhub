// Authored by: prid1306
// BOJ 17619 greedy + union-find?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using tiii = tuple<int,int,int>;
vector<int> p(1'000'001, -1);
vector<tuple<int,int,int>> v; //startpos, endpos, num

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
        swap(u,v);
    if(p[v] == p[u])
        p[u]--;
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){ //sorting
        int x1,x2,y; cin>>x1>>x2>>y;
        v.push_back({x1, x2, i+1});
    }
    sort(v.begin(),v.end());
    int st = get<0>(v[0]),en = get<1>(v[0]);
    for(int i=1;i<v.size();i++){
        if(get<0>(v[i]) <= en){
            uni(get<2>(v[i]), get<2>(v[i-1]));
            en = max(en, get<1>(v[i]));
        }else{
            st = get<0>(v[i]);
            en = get<1>(v[i]);
        }
    }
    while(q--){
        int a,b;cin>>a>>b;
        //cout<<find(a)<<" and "<<find(b)<<'\n';
        if(find(a) == find(b)) cout<<"1\n";
        else cout<<"0\n";
    }
}