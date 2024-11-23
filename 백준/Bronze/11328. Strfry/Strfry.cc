#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        bool ispos=true;
        string a,b;
        cin>>a>>b;
        if(a.length()!=b.length()){
            cout<<"Impossible"<<'\n';
            continue;
        }

        int alp[26]={0,};

        for(char i:a) alp[i-'a']++;
        for(char i:b) alp[i-'a']--;

        for(int i : alp){
            if(i!=0){
                cout<<"Impossible"<<'\n';
                ispos =false;
                break;
            }
        }
        if(ispos) cout<<"Possible"<<'\n';
    }
}