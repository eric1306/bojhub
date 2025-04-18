//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    while(a!=0 && b!=0 && c!=0)
    {
        if(a < b){
            swap(a,b);
        }
        if(a < c){
            swap(a,c);
        }
        bool result = (a*a == b*b + c*c);
        if(result)cout<<"right"<<'\n';
        else cout<<"wrong"<<'\n';
        cin>>a>>b>>c;
    }
}