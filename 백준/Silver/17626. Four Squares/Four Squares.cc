// Authored by: prid1306
#include <iostream>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int d[50001];
int main(){
    FASTIO;
    int n;cin>>n;
    fill(d, d+50001, 1e9);
    for(int i=1;i*i<=n;i++){
        d[i*i] = 1;
    }
    for(int i=2;i<=n;i++){
        if(d[i] == 1) continue;
        for(int j=1;j*j<=i;j++){
            d[i] = min(d[i], d[i-j*j] + 1);
            // cout<<"d["<<i<<"]: "<<d[i]<<'\n';
        }
        // cout<<"result: d["<<i<<"]: "<<d[i]<<'\n';
        // cout<<"--------------\n";
    }
    cout<<d[n];
}