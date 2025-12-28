// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,k;
int ans = -1;
int reverseInt(int i)
{
    int ret = 0;
    while(i)
    {
        ret = ret * 10 + i%10;
        i/=10;
    }
    return ret;
}
int main(){
    FASTIO;
    cin>>n>>k;
    int multi = 0;
    for(int i=1;i<=k;i++)
    {
        multi += n;
        int value = reverseInt(multi);
        if(ans < value) ans = value;
    }
    cout<<ans;
}