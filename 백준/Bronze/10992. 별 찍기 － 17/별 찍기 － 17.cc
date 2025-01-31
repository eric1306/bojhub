#include <iostream>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0;i<n-1;i++) cout<<' ';
    cout<<'*'<<'\n';
    for(int i=0;i<n-1;i++){
        if(i == n-2){
            for(int j=0;j<2*(n-1)+1;j++) cout<<'*';
        }
        else
        {
            for(int j=i+1;j<n-1;j++) cout<<' ';
            cout<<'*';
            for(int j=0;j<2*i+1;j++) cout<<' ';
            cout<<'*';
        }
        cout<<'\n';
    }
}