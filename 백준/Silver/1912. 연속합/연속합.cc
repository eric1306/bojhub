//Authored by: prid1306
#include <iostream>
using namespace std;
int n;
int arr[100001];
int d[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    d[1] = arr[1];
    for(int i=2;i<=n;i++){
        d[i] = max(arr[i],d[i-1] + arr[i]);
    }
    int max = -1001;
    for(int i=1;i<=n;i++){
        if(max < d[i]) max = d[i];
    }
    cout<<max;
    
}