// Authored by: prid1306
#include <iostream>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using ll = long long;
const int R = 31;
const int M = 1'234'567'891;
ll CPOW(int x){
    ll ret  = 1;
    while(x--){
        ret*= R;
        ret%=M;
    }
    return ret;
}
int main(){
    FASTIO;
    int L;cin>>L;
    string s; cin>>s;
    ll ans = 0;
    for(int i=0;i<L;i++){
        ll tmp = (s[i] - 'a' + 1) * CPOW(i) % M;
        ans+=tmp;
        ans%=M;
    }
    cout<<ans;
}