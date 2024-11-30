#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string n;
    cin>>n;
    for(int i=0;i<n.length();i++){
        if(i%10 == 0 && i!=0) cout<<'\n';
        cout<<n[i];
    }
}