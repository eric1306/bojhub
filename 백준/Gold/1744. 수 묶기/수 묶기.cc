//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[50];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    if(n == 1)
    {
        cout<<a[0];
        return 0;
    }
    for(int i=n-1;a[i]>0;i--)
    {
        if(a[i] * a[i-1] > 0 && a[i] * a[i-1] > a[i] + a[i-1])
        {
            ans += a[i] * a[i-1];
            if(i > 0) i--;
        }
        else{
            ans += a[i];
        }
    }
    for(int i=0; a[i]<=0;i++)
    {   
        if(i+1 < n && a[i+1] <=0)
        {
            ans +=a[i] * a[i+1];
            if(i < n-1) i++;
        }
        else
        {
            ans+=a[i];
        }
    }
    cout<<ans;
}