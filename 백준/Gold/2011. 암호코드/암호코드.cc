//Authored by: prid1306
#include <iostream>
using namespace std;
string n;
const int MOD = 1000000;
int d[5001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    if(n[0] ==  '0'){
        cout<<0;
        return 0;
    }
    d[0] = 1;
    d[1] = 1;
    for(int i=2;i<=n.size();i++)
    {
        if(n[i-1] != '0')
            d[i] = d[i-1];
        if ((n[i-2]!='0')&& (((int)(n[i-2] - '0')*10 + (int)(n[i-1] - '0')) <= 26))
        {
            d[i]+=d[i-2];
        }
        d[i]%=MOD;
    }
    cout<<d[n.size()];
}