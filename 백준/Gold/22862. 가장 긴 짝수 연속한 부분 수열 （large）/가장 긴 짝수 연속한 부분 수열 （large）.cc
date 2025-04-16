//Authored by: prid1306
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int a[1'000'001];
    for(int i=0;i<n;i++) cin>>a[i];
    int ans = 0;
    int en = 0;
    int oddnum = 0, evennum = 0;
    /*
    st부터 en까지 중에서 짝수의 수와 홀수의 개수를 동시에 체크
    만약 홀수의 개수가 k를 초과한다면 st를 ++시켜서 k개 이하를 만족할 때 까지 이동시키기.
    */
    int st = 0;
    (a[0] % 2 == 0) ? evennum++ : oddnum++;
    while(st < n)
    {
        while(en < n && oddnum <= k)
        {
            en++;
            if(en!=n)
            {
                (a[en] % 2 == 0) ? evennum++ : oddnum++;
            }
        }
        ans = max(ans, evennum);
        //cout<<ans << ' '<<evennum<<' '<<oddnum<<' '<<st<<' '<<en<<'\n';
        if(en == n) break;

        while(oddnum > k)
        {
            (a[st]%2 == 0) ? evennum-- : oddnum--;
            st++;
        }
        //cout<<ans << ' '<<evennum<<' '<<oddnum<<' '<<st<<' '<<en<<'\n';
    }
    cout<<ans;
}