#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<i;j++) cout<<'*';
        cout<<'\n';
    }
    for(int i = n-1; i>=1;i--) {
        for(int j=0;j<i;j++) cout<<'*';
        cout<<'\n';
    }
}