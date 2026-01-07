// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int x,y;
int main(){
    FASTIO;
    cin>>x>>y;
    for(int i=x;i<=y;i+=60)
    {
        cout<<"All positions change in year "<<i<<'\n';
    }
}