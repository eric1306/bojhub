//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int n,s;
int a[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0;i<n;i++) cin>>a[i];
    int en = 0;
    int ans = 0x7fffffff;
    int sum = a[0];
    int len = 1;
    for(int st = 0; st < n; st++)
    {
        while(en < n && sum < s){
            sum+=a[++en];
            len++;
        }
        if(en == n) break;
        ans = min(ans, len);

        sum -= a[st];
        len--;
    }
    if(ans == 0x7fffffff) cout<<0;
    else cout<<ans;
}