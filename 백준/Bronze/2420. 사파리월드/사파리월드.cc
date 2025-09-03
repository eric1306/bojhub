// Authored by: prid1306
// BOJ 
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m; cin>>n>>m;
    // int ans = n >= m ? n - m : m - n;
    // cout<<ans;
    cout<<(n >= m ? n - m : m - n);
}