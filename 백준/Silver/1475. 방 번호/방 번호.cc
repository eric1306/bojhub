#include <bits/stdc++.h>
using namespace std;
int arr[10]; //0~9
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;

    while(n){
        int k = n%10;
        arr[k]++;
        n=n/10;
    }
    
    int six_nine = (arr[6]+arr[9])/2 + (arr[6]+arr[9])%2;
    arr[6] = six_nine;
    arr[9] = six_nine;
    int max = -1;

    for(int i:arr){
        if(i>max) max = i;
    }
    cout<<max;
}