#include <bits/stdc++.h>
using namespace std;
int minodd = 101;
int inp, ans = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 7;
    while(cnt--){
        cin>>inp;
        if(inp%2) {
            ans += inp;
            if(minodd > inp) minodd = inp;
        }
    }

    if(ans)cout<<ans<<'\n'<<minodd;
    else cout<<-1;
}