// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using ull = unsigned long long;
/* 
이진수 패턴을 보고 도출해보자
0 
1 -> 1 + 0 = 1개
10
11 -> 2 + 1 = 3개 = 2^2 - 1 
100 
101
110
111 -> 4 + 1 + 3 = 8개 -> 2^3
1000 1
1001 2
1010 2
1011
1100 (1 + 3 + 8) + (12 - 8 + 1) + 1 + 3 + (4 - 4 + 1)
1101
1110
1111 -> 8 + 1개 + 3개  + 8개 = 20개
10000
10001
10010
10011
10100
10101 (1 + 3 + 8 + 20) + 4 + 1
10110
10111
11000
11001
11010
11011
11100
11101
11110(1 + 3 + 8 + 20)
11111 -> 16 + 1 + 3 + 8 + 20 = 48개
n이 있을 때, 
a,b의 범위가 10'000'000'000'000'000
*/

/*
범위가 10^16인거 보니까 뭔가 분할정복 각이다.
아니지 분할정복할 필요가 없네
자릿수가 n개일때 1의 개수를 알 수 있잖아?
sqrt(b)
sqrt
*/

ull arr[65];
ull sum_a[65];

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
    sum_a[0] = 0;
    for(int i=1;i<=64;i++)
    {
        arr[i] = _pow + sum;
        sum_a[i] = sum_a[i-1] + arr[i];
        _pow *= 2;
        sum += arr[i];
    }
    
    ull comp = 1LL << 63;
    ull ans = CountOne(comp, 63, b) - CountOne(comp, 63, a);
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