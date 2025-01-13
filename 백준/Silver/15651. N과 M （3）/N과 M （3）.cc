#include <iostream>
using namespace std;
int n,m;
int arr[10];

void func(int k){
    if(k == m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }

    for(int i=0;i<n;i++){
        /*idx와 value가 다르게 들어가야함*/
        int t = 0;
        while(arr[t]){
            t++;
        }
        arr[t] = i+1;
        func(k+1);
        arr[t] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    func(0);
}