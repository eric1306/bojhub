//Authored by: prid1306
#include <iostream>
int n,k;
int a[15];
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i = n-1;i>=0;i--)
    {
        ans += k / a[i];
        k%=a[i];
    }
    cout<<ans;
}