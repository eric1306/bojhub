// Authored by: prid1306
// BOJ 2738
#include <iostream>
using namespace std;
int a[10001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        cin>>a[i*m + j];
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        int tmp; cin>>tmp;
        a[i*m + j] += tmp;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i*m + j]<<' ';
        }
        cout<<'\n';
    }
}