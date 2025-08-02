// Authored by: prid1306
// BOJ 24389
#include <iostream>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int rev_n = ~n + 1;
    int ret = n ^ rev_n;
    int ans = 0;
    for(int i=0;i<32;i++){
        int tmp = 1;
        if(ret & (tmp << i)){
            ans++;
        }
    }
    cout<<ans;
}