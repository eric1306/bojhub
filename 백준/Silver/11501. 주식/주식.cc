//Authored by: prid1306
#include <iostream>
using namespace std;
int t,n;
int arr[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        fill(arr,arr+n,0);
        for(int i=0;i<n;i++) cin>>arr[i];
        int _max = arr[n-1];
        long long ans = 0;
        for(int i=n-2;i>=0;i--)
        {
            if(_max > arr[i]) ans += _max - arr[i];
            else _max = arr[i];
        }
        cout<<ans<<'\n';
    }
}