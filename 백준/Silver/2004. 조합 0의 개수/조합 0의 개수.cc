//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
using ull = unsigned long long;

ull two, five, n, m;

ull GetNum(ull x, ull div)
{
    ull ret = 0,tmp = div;
    while(x / tmp)
    {
        ret += (x / tmp);
        tmp*=div;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    two = GetNum(n,2) - GetNum(m,2) - GetNum((n-m), 2);
    five = GetNum(n,5) - GetNum(m,5) - GetNum((n-m), 5);
    cout<<min(two, five);
}