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
    string s, p;
    cin>>s>>p;
    string _s = "";
    for(auto c : s)
    {
        if((int)(c - '0') >= 10 || (int)(c - '0') < 0)
        {
            _s+=c;
        }
    }
    s = _s;
    vector<int> f = failure(p);
    int j=0;
    //실패함수 로직과 굉장히 비슷함.
    for(int i=0;i<s.size();i++){
        while(j>0 && s[i]!=p[j]) j = f[j-1];
        if(s[i] == p[j]) j++;
        if(j== p.size()){ // -> 문자열 s안에 문자열 p가 들어있음.
            cout<<1;
            return 0;
        }
    }
    cout<<0;
}