//Authored by: prid1306
#include <iostream>
using namespace std;
int n;
/*i자리 이천수의 개수, 마지막에 사용한 숫자는 j*/
using ull = unsigned long long;
ull d[91][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    d[1][1] = 1;
    d[2][0] = 1;
    d[3][0] = 1;
    d[3][1] = 1;
    for(int i=4;i<=n;i++)
    {
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }
    cout<<d[n][0] + d[n][1];
}