//Authored by: prid1306
#include <iostream>
using namespace std;
using ull = unsigned long long;
int t,n;
ull d[101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    d[1] = 1;d[2] = 1;d[3] = 1;d[4] = 2;d[5] =2; d[6] = 3;
    for(int i=7;i<=101;i++)
    {
        d[i] = d[i-1] + d[i-5];
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<d[n]<<'\n';
    }
}