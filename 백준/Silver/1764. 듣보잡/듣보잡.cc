// Authored by: prid1306
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
vector<string> v;
vector<string> ans;
int main(){
    FASTIO;
    int n,m;cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++){
        string s;cin>>s;
        int idx = lower_bound(v.begin(),v.end(), s) - v.begin();
        if(v[idx] == s && idx !=v.size()) ans.push_back(s);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto elem : ans){
        cout<<elem<<'\n';
    }
}