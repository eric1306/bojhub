// Authored by: prid1306
#include <iostream>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int d[301];
int stairs[301];
int main(){
    FASTIO;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stairs[i];
    }
    d[1] = stairs[1];
    d[2] = stairs[1] + stairs[2];
    for(int i=3;i<=n;i++){
        d[i] = max(d[i-2], d[i-3] + stairs[i-1]) + stairs[i];
    }
    cout<<d[n];
}