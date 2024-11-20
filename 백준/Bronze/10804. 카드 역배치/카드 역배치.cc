#include <bits/stdc++.h>
using namespace std;
int arr[21] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 10,a,b;
    while(cnt--){
        cin>>a>>b;
        for(int i=a; i <=(a+b)/2; i++){
            int tmp = arr[i];
            arr[i] = arr[b+a-i];
            arr[b+a-i] = tmp;
        }
    }
    for(int i=1;i<=20;i++){
        cout<<arr[i]<<' ';
    }
}