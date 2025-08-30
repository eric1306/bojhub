// Authored by: prid1306
// BOJ 12784
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v[1001];

int DFS(int cur, int pre)
{
    int ret = 0,flag = 1;
    for(auto [x, y] : v[cur]){
        if(x == pre) continue;
        ret += min(DFS(x, cur), y);
        flag = 0;
    }
    if(flag) ret = 1e9;
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--) //100
    {
        int n,m;cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y,value;cin>>x>>y>>value;
            v[x].push_back({y, value});
            v[y].push_back({x, value});
        }
        if(n == 1){
            cout<<0<<'\n';
            continue;
        }
        cout<<DFS(1, -1)<<'\n';
        for(int i=0;i<1001;i++){
            v[i].clear();
        }
    }
}