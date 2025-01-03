#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n+2;i++) cout<<'@';
    cout<<'\n';
    for(int i=2;i<=n+1;i++){
        cout<<'@';
        for(int j=0;j<n;j++) cout<<' ';
        cout<<'@';
        cout<<'\n';
    }
    for(int i=0;i<n+2;i++) cout<<'@';
}