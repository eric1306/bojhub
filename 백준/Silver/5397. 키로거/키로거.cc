#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    list<char> l={};
    int cnt;
    cin>>cnt;

    while(cnt--){
        string n;
        cin>>n;
        auto t = l.begin();
        for(char i : n){
            if(i == '<'){
                if(t!=l.begin()) t--;
            }else if(i == '>'){
                if(t!=l.end()) t++;
            }else if(i == '-'){
                if(t!=l.begin()){
                    t = l.erase(--t);
                }
            }else{ //정상적인 문자 삽입
                l.insert(t,i);
            }
        }

        for(auto i : l) cout<<i;
        cout<<'\n';

        l.clear();
    }
}