#include <bits/stdc++.h>
using namespace std;
int ans;
string a,b;
int stra[26];
int strb[26];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    for(char i : a) stra[i-'a']++;
    for(char i : b) strb[i-'a']++;
    for(int i=0;i<26;i++){
        if(stra[i]!=strb[i]) ans+= (stra[i] - strb[i]) > 0 ? (stra[i] - strb[i]) : ( strb[i] - stra[i]);
    }
    cout<<ans;
}