// Authored by: prid1306
// BOJ 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define x first
#define y second
vector<int> p(1'000'001, -1);
vector<pair<int,int>> v;
int n,m;

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){
        return false;
    }
    if(p[v] < p[u]){
        swap(u,v);
    }
    if(p[v] == p[u]){
        p[u]--;
    }
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    if(m == 0){
        cout<<n;return 0;
    }
    //x, y가 입력됐을 때 그 사이에 있는 모두를 그룹으로 편입 시키는 방법
    //sweeping으로 판단하면서 건너가기
    while(m--){
        int x,y;cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    //cout<<v.size();
    int st = v[0].x;
    int en = v[0].y;
    for(int i=1;i<v.size();i++){
        if(v[i].x <= en){
            en = max(en, v[i].y);
        }else{
            uni(st, en);
            st = v[i].x;en = v[i].y;
        }
    }
    uni(st, en);
    int ans = n;
    int rem = 0;
    for(int i=1;i<=n;i++){
        //cout<<"i: "<<i<<" p[i]: "<<p[i]<<"\n";
        if(rem == 0 && find(i) == i && p[i] < -1){
            //cout<<"this is root"<<'\n';
            rem = i;
            continue;
        }
        else if(p[i] == rem){
            ans -= (i - rem);
            rem = 0;
        }
    }
    cout<<ans;
}