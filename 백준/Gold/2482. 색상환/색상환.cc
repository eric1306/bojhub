// Authored by: prid1306
// BOJ 2482
#include <iostream>
using namespace std;
int d[1001][1001];
const int DIV = 1e9 + 3;
int n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    //Initialize
    for(int i=1;i<=n;i++) d[i][1] = i;
    //answer
    for(int i=4;i<=n;i++){
        for(int j=2;j<=k;j++){
            if(j>i/2) break;
            d[i][j] = (d[i-1][j] + d[i-2][j-1])%DIV;
        }
    }
    cout<<d[n][k];
}