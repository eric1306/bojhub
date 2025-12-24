// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main(){
    FASTIO;
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        while(n--)
        {
            int a,b;
            cin>>a>>b;
            cout<<a + b<<' '<<a * b<<'\n';
        }
    }
}