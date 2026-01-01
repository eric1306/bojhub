// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using ull = unsigned long long;
/*
n이 4000까지임. n^3까지도 허용이 안됨.
*/
int n;
ull ans;
vector<int> va;
vector<int> vb;
vector<int> vc;
vector<int> vd;
vector<int> sum_ab;
int main(){
    FASTIO;
    cin>>n;
    va.resize(n);
    vb.resize(n);
    vc.resize(n);
    vd.resize(n);
    sum_ab.resize(n*n);
    for(int i=0;i<n;i++)
        cin>>va[i]>>vb[i]>>vc[i]>>vd[i];
    
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        int sum = va[i] + vb[j];
        sum_ab[i*n + j] = sum;
    }
    sort(sum_ab.begin(), sum_ab.end());
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        int sum = vc[i] + vd[j];
        auto it = equal_range(sum_ab.begin(), sum_ab.end(), -sum);
        if(it.first!=sum_ab.end() && *it.first == -sum)
        {
            ans += it.second - it.first;
        }
    }
    cout<<ans;
}