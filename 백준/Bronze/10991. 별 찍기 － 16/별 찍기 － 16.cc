#include <iostream>
using namespace std;

int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n-1;j++) cout<<' ';
        cout<<"*";
        for(int j=0;j<2*i;j++){
            if(j%2 == 0) cout<<' ';
            else cout<<'*';
        }
        cout<<'\n';
    }
}