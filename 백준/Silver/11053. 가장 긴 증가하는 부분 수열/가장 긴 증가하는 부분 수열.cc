// Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int a[1001];
int main(){
    FASTIO;
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> lis;
    for(int i=1;i<=n;i++){
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if (it == lis.end()) {
            lis.push_back(a[i]);
        }else{
            *it = a[i];
        }
    }
    cout<<lis.size();
}