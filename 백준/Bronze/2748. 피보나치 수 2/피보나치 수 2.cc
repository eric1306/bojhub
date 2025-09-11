// Authored by: prid1306
// BOJ 2748 fibonacci 2
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
ll memo[91];

ll fibo(int n){
    if(n < 2) return n;
    if(memo[n]!= - 1) return memo[n];
    return memo[n] = fibo(n-1) + fibo(n-2);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    fill(memo, memo+91, -1);
    cout<<fibo(n);
}