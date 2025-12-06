// Authored by: prid1306
#include <iostream>
#include <cmath>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using pll = pair<long long,long long>;
#define x first
#define y second
/*
n각형의 면적을 구하는 프로그램.
n == 3
*/
int n;
pll fPos;
pll sPos;
pll tPos;
double ans;
int main(){
    FASTIO;
    cin>>n;
    cin>>fPos.x>>fPos.y;
    cin>>sPos.x>>sPos.y;
    for(int i=0;i<n-2;i++)
    {
        cin>>tPos.x>>tPos.y;
        double ret = ((fPos.x * sPos.y + sPos.x*tPos.y + tPos.x * fPos.y) - (sPos.x * fPos.y + tPos.x * sPos.y + fPos.x * tPos.y))/2.0;
        ans+= ret;
        sPos = tPos;
    }
    cout<<fixed;
    cout.precision(1);
    ans = abs(ans);
    ans = round(ans * 10) / 10;
    cout<<ans<<'\n';
}