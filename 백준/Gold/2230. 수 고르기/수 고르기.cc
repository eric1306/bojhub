//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    int st = 0,en = 0,ans = 0x7fffffff;
    sort(a,a+n);
    while(st < n && en < n)
    {
        if(a[en] - a[st] < m)
        {
            en++;
        }
        else if(a[en] - a[st] >= m)
        {
            ans = min(ans, a[en]-a[st]);
            st++;
        }
    }
    cout<<ans;
}