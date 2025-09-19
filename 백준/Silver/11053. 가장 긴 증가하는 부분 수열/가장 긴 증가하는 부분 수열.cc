// Authored by: prid1306
#include <iostream>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int d[1001];
int a[1001];
int main(){
    FASTIO;
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    fill(d+1, d+n+1, 1);
    for(int i=2;i<=n;i++){
        for(int j=i-1; j>=1;j--){
            if(a[j] < a[i])
            d[i] = max(d[i], d[j]+ 1);
        }
    }
    cout<<*max_element(d+1, d+1001);
}