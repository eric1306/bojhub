// Authored by: prid1306
#include <iostream>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int d[301][3];
int stairs[301];
int main(){
    FASTIO;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stairs[i];
    }
    d[1][1] = stairs[1]; 
    d[2][1] = stairs[2];d[2][2] = d[1][1] + stairs[2];
    for(int i=3;i<=n;i++){
        d[i][1] = max(d[i-2][1], d[i-2][2]) + stairs[i];
        d[i][2] = d[i-1][1] + stairs[i];
    }
    int ans = -1;
    for(int i=0;i<3;i++){
        if(ans < d[n][i]) ans = d[n][i];
    }
    cout<<ans<<'\n';
}