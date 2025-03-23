//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long ans;
int a[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++) 
    {
        for(int j=i+1;j<n;j++)
        {
            int* lb = lower_bound(a+j+1,a+n,-a[i]-a[j]);
            int* ub = upper_bound(a+j+1,a+n,-a[i]-a[j]);
            ans+=ub-lb;
        }
    }
    
    cout<<ans;
}