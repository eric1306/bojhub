//Authored by: prid1306
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    unordered_set<string> s;
    cin>>n;
    string pre,post;
    while(n--)
    {
        cin>>pre>>post;
        if(post == "leave") s.erase(pre);
        else s.insert(pre);
    }
    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for(auto c : ans) cout<<c<<'\n';
}