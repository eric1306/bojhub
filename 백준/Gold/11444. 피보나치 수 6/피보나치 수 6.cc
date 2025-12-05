// Authored by: prid1306
#include <iostream>
#include <string>
#include <map>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
//n <= 10^18
/*
단순 덧셈인데 분할 정복이 가능한가..?
분할 정복 거듭제곱? 피보나치는 덧셈인데 왜 거듭제곱이 튀어나오지?
제한 범위 100경 -> logn까지 떨궈야 할듯?
*/
using ull = unsigned long long;
map<ull, ull> m;
const int MOD = 1'000'000'007;

ull fibo(ull n)
{
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else if(n == 2) return 1;

    auto it = m.count(n);
    if(it != 0) return m[n];
    
    if(n%2 == 0)
        return m[n] = (fibo(n/2) % MOD * (fibo(n/2 + 1) % MOD + fibo(n/2 - 1)%MOD) % MOD) % MOD;
    else 
        return m[n] = ((fibo(n/2 + 1)%MOD) * (fibo(n/2 + 1)%MOD) % MOD + (fibo(n/2)%MOD) * (fibo(n/2)%MOD) % MOD) % MOD;
}
int main(){
    FASTIO;
    ull n;
    cin>>n;
    m[0] = 0;
    m[1] = 1;
    m[2] = 2;
    
    cout<<fibo(n);
}