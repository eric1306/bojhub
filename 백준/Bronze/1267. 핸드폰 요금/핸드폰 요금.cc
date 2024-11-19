#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[21],n,Y=0,M=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        Y += (arr[i]/30)*10+10;
        M += (arr[i]/60)*15+15;        
    }

    if (Y<M) cout<<"Y "<<Y;
    else if(M<Y) cout<<"M "<<M;
    else cout<<"Y M "<<Y;
}