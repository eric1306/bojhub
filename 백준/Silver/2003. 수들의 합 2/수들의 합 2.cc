//Authored by: prid1306
#include <iostream>
using namespace std;
int n,m;
int a[10001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    int en = 0;
    int sum = a[0];
    int ans = 0;
    for(int st=0;st<n;st++)
    {
        while(en < n && sum < m){
            en++;
            if(en!=n) sum+=a[en];
        }
        if(en == n) break;
        if(sum == m) ans++;
        sum -= a[st];
    }
    cout<<ans;
}