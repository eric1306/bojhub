#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int up = 1;
    for(int i=n;i>n-k;i--) up*=i;
    int down = 1;
    for(int i=2;i<=k;i++) down *=i;
    cout<<up/down;
}