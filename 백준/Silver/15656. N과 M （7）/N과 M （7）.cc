#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[10];
int arrs[10];

void func(int k){
    if(k == m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        // int t = 0;
        // while(arr[t]) t++;
        arr[k] = arrs[i];
        func(k+1);
        arr[k] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arrs[i];
    sort(arrs, arrs+n);
    func(0);
}