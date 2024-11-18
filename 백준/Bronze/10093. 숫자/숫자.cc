#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>a>>b;

    if(a>b){
        long long tmp = a;
        a = b;
        b = tmp;
    }
    if(a==b)cout<<0<<'\n';
    else cout<<b-a-1<<'\n';
    
    while(a<b-1){
        cout<<++a<<' ';
    }
}