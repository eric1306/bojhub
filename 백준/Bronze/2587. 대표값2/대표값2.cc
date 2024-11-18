#include <bits/stdc++.h>
using namespace std;
int arr[5],avg = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<5;i++){
        cin>>arr[i];
        avg += arr[i]/5;
    }    
    sort(arr, arr+5);
    cout<<avg<<'\n'<<arr[2];

}