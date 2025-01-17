#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[10];
bool isused[10];
int arrs[10];

void func(int k){
    if(k == m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++)
    {
        int t = 0;
        while(arr[t]) t++;
        if(arr[t-1] < arrs[i]){
            arr[t] = arrs[i];
            func(k+1);
            arr[t] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arrs[i];
    sort(arrs,arrs+n+1);
    func(0);
}