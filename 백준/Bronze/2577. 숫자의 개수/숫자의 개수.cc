#include <bits/stdc++.h>
using namespace std;
int arr[10]={0,};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,ans;
    cin>>a>>b>>c;
    ans = a*b*c;
    while(ans/10!=0){
        arr[ans%10]++;
        ans/=10;
    }
    arr[ans]++;
    for(int i:arr) cout<<i<<'\n';
}