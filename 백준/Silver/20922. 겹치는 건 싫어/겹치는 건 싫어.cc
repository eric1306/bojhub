//Authored by: prid1306
#include <iostream>
using namespace std;
int n,k;
int a[200'001];
int cnt[100'001];

bool IsCorret()
{
    for(auto c : cnt)
    {
        if(c > k)
            return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    int st = 0,en = 0;
    int ans = 0;
    cnt[a[0]]++;
    while(st < n && en < n)
    {
        while(en < n && cnt[a[en]] <= k)
        {
            en++;
            if(en!=n)
            {
                cnt[a[en]]++;
            }
        }
        if(en == n)
        {
            ans = max(ans, en - st);
            break;
        }
        ans = max(ans, en-st);
        while(cnt[a[en]] > k)
        {
            cnt[a[st++]]--;
        }
    }
    cout<<ans;
}