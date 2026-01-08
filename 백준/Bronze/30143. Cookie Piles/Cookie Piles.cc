// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main(){
    FASTIO;
    int t;cin>>t;
    while(t--)
    {
        int n,a,d;
        cin>>n>>a>>d;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += a;
            a+=d;
        }
        cout<<sum<<'\n';
    }
}