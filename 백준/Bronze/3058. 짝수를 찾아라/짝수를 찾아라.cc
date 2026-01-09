// Authored by: prid1306
#include <iostream>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main(){
    FASTIO;
    int t;cin>>t;
    while(t--)
    {
        int _min = 0x3fffffff;
        int sum = 0;
        for(int i=0;i<7;i++)
        {
            int a;cin>>a;
            if(a%2 == 0)
            {
                _min = min(a, _min);
                sum += a;
            }
        }
        cout<<sum<<' '<<_min<<'\n';
    }
}