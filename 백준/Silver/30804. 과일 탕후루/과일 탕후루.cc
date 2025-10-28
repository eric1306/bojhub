// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;


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
        while(10 - count(c.begin(), c.end(), 0) > 2)
            c[v[l++]]--;
        ans = max(ans, r - l);
    }
    cout<<ans;
}