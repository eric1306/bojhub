#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b&&b==c){
        cout<<10000+a*1000;
    }else if(a==b||b==c||c==a){
        cout<<1000+(a==b?a:b==c?b:c)*100;
    }else cout<<(a>b?(a>c?a:(b>c?b:c)):(b>c?b:(a>c?a:c)))*100;
}