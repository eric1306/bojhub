//Authored by: prid1306
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> failure(string& s){
    vector<int> f(s.size());
    int j = 0;
    for(int i=1;i<s.size();i++){
        while(j>0 && s[i]!=s[j]) j=f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> ans;
    string s, p;
    getline(cin, s);
    getline(cin,p);
    vector<int> f = failure(p);
    int j=0;
    for(int i=0;i<s.size();i++){
        while(j>0 && s[i]!=p[j]) j = f[j-1];
        if(s[i] == p[j]) j++;
        if(j== p.size()){ // -> 문자열 s안에 문자열 p가 들어있음.
            ans.push_back(i-j+2);
            continue;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto c : ans) cout<<c<<' ';
} 