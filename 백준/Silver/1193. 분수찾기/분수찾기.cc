//Authored by: prid1306
#include <iostream>
using namespace std;
int x;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>x;
    int _max = x;
    int num;
    for(int i=1;i<=x;i++)
    {
        if(_max - i > 0) _max -=i;
        else{
            num = i;
            break;
        }
    }
    if((num+1)%2 != 0) cout<<_max<<"/"<<(num+1) - _max;
    else cout<<(num+1) - _max<<"/"<<_max;
}