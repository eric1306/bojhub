#include <bits/stdc++.h>
using namespace std;
int n,tmp;
int arr[10001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        arr[tmp]++;
    }
    
    for(int i=1;i<=10000;i++){
        for(int j=0;j<arr[i];j++) cout<<i<<'\n';
    }
}