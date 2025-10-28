// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int CheckFruitType(const vector<int>& v)
{
    int ret = 0;
    for(auto elem : v){
        if(elem != 0) ret++;
    }
    return ret;
}

int main(){
    FASTIO;
    int n,ans = 0;cin>>n;
    vector<int> v(n);
    vector<int> c(10, 0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int l=0,r=0;
    while(r < n)
    {
        c[v[r++]]++;
        while(CheckFruitType(c) > 2)
            c[v[l++]]--;
        ans = max(ans, r - l);
    }
    cout<<ans;
}