// Authored by: prid1306
// BOJ 17619 greedy + union-find?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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
    if(u == v)
        return false;
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
    int n,q;
    cin>>n>>q;
    int cnt = 1;
    while(n--){ //sorting
        int x1,x2,y; cin>>x1>>x2>>y;
        v.push_back({x1, x2, cnt});
        cnt++;
    }
    sort(v.begin(),v.end());
    //여기서 union 진행
    for(int i=0;i<v.size()-1;i++){
        int st,en,num,st2,en2,num2;
        tie(st,en,num) = v[i];tie(st2,en2,num2) = v[i+1];
        if(en >= st2){
            uni(num, num2);
        }
    }
    while(q--){
        int a,b;cin>>a>>b;
        if(find(a) == find(b)) cout<<"1\n";
        else cout<<"0\n";
    }
}