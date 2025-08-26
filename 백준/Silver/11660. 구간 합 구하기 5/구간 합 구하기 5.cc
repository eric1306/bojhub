// Authored by: prid1306
// BOJ 11660
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[1024][1024];
int d[1025][1025]; //d[i][j]
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        d[i][1] = a[i][0];
        d[1][i] = a[0][i];
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        d[i][j] = a[i-1][j-1] +d[i-1][j] + d[i][j-1] - d[i-1][j-1];
    }

    while(m--)
    {
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2; // 2, 3, 4, 5
        //답은, d[x2][y2] - d[x1][y2] - d[x2][y1] + d[x1][y1];
        cout<<d[x2][y2] - d[x1-1][y2] - d[x2][y1-1] + d[x1-1][y1-1]<<'\n';
    }
}