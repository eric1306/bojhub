#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

ll solve(ll k)
{
    if(k == 1 || k == 2 || k == 3)
        return k;
    else{
        ll sum = 1, l;
        l = sqrt(k);
        sum = (l*l + (l+1)*(l+1))/2;

        if(k == l*l) return 2*l - 1;

        if(k > sum)
        {
            return l*2+1;
        }else{
            return l*2;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    ll x, y;
    while(t--){
        cin>>x>>y;
        cout<<solve(y - x) << '\n';
    }
}