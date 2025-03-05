//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int p[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    sort(p,p+n);
    int ans = 0,cursum = 0;
    for(int i=0;i<n;i++){
        ans += cursum + p[i];
        cursum +=p[i];
    }
        
    cout<<ans;
}