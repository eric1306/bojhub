// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using ull = unsigned long long;
const int MAX = 64;
ull arr[MAX+1];
ull sum_a[MAX+1];

ull GetPow(int idx)
{
    ull ret = 1;
    while(idx--)
    {
        ret *= 2;
    }
    return ret;
}

ull CountOne(ull comp, int idx, ull n)
{
    if(n == 0 || idx == 0) return 0;
    while(true)
    {
        if(n & comp)
        {
            break;
        }
        comp = comp >> 1;
        idx--;
    }
    ull new_n = n - GetPow(idx);
    return sum_a[idx] + new_n + 1 + CountOne(comp, idx, new_n);
}

int main(){
    FASTIO;
    ull a,b;
    cin>>a>>b;
    ull _pow = 1;
    ull sum = 0;
    for(int i=1;i<=MAX;i++)
    {
        arr[i] = _pow + sum;
        sum_a[i] = sum_a[i-1] + arr[i];
        _pow *= 2;
        sum += arr[i];
    }
    
    ull comp = 1LL << MAX-1;
    ull ans = CountOne(comp, MAX-1, b) - CountOne(comp, MAX-1, a);
    while(comp > 0)
    {
        if(a & comp)
        {
            ans++;
        }
        comp = comp >> 1;
    }
    cout<<ans;
}