//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n,greater<>());
    int max = 0;
    for(int i=1;i<=n;i++)
    {
        int tmp = arr[i-1] * i;
        if(max < tmp) max = tmp;
    }
    cout<<max;
}