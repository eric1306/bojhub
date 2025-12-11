// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main(){
    FASTIO;
    int a,b;cin>>a>>b;
    int ret = (a/2) >= b ? b : a/2;
    cout<<ret;
}