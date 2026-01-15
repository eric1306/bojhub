// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main(){
    FASTIO;
    int x1, x2, x3, y1, y2, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int ret = CCW(x1, y1, x2, y2, x3, y3);
    if(ret == 0) cout<<0;
    else if(ret > 0) cout<<1;
    else cout<<-1;
}