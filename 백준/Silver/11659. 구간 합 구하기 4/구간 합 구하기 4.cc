#include <iostream>
using namespace std;
int d[100001];
int k[100001];
int n,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int r,c;
    for(int i=1;i<=n;i++){
        cin>>r;
        k[i] = r;
    }
    d[1] = k[1];
    for(int i=2;i<=n;i++){
        d[i] = d[i-1] + k[i];
    }
    while(m--){
        cin>>r>>c;
        cout<<(d[c] - d[r-1])<<'\n';
    }
}