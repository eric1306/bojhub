// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using ll = long long;

int k,n;
vector<int> v;

bool solve(int div)
{
    ll ret = 0;
    for(auto elem : v)
    {
        ret += (elem/div);
    }
    return ret >= n;
}

int main(){
    FASTIO;
    
    cin>>k>>n;
    for(int i=0;i<k;i++){
        int input;cin>>input;
        v.push_back(input);
    }
    ll st = 1;
    ll en = 0x7fffffff; //2^31 - 1 
    while(st < en)
    {
        ll mid = (st + en + 1)/2;
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }
    cout<<st;
}