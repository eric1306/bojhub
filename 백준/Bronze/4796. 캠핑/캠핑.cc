//Authored by: prid1306
#include <iostream>
using namespace std;
int l,p,v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 1;
    //ㅅㅂ 이게 한국어임?
    cin>>l>>p>>v;
    while(l!=0 && p!=0&&v!=0)
    {
        //5 11 21
        int div = v%p > l ? l : v%p;
        cout<<"Case "<<cnt++<<": "<<(v/p)*l + div<<"\n";
        cin>>l>>p>>v;
    }
}