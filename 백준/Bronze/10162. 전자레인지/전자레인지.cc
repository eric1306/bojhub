//Authored by: prid1306
#include <iostream>
using namespace std;
const int min_5 = 300;
const int min_1 = 60;
const int sec_10 = 10;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int a,b,c;
    a = t/min_5;t%=min_5;
    b = t/min_1;t%=min_1;
    c = t/sec_10;t%=sec_10;
    if(t)
    {
        cout<<-1;
        return 0;
    }
    else
    {
        cout<<a<<' '<<b<<' '<<c;
    }
}