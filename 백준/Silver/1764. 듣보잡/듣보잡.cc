// Authored by: prid1306
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
map<string, int> _m;
int main(){
    FASTIO;
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        _m[s]++;
    }
    for(int i=0;i<m;i++)
    {
        string s; cin>>s;
        _m[s]++;
    }
    vector<string> ans;
    for(auto c : _m){
        if(c.second == 2){
            ans.push_back(c.first);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto c : ans){
        cout<<c<<'\n';
    }
}