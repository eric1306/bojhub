//Authored by: prid1306 // LCS
#include <iostream>
#include <string>
using namespace std;
string n,m;
int d[1001][1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n.size();i++) d[i][0] = 0;
    for(int i=0;i<m.size();i++) d[0][i] = 0;
    for(int i=1;i<=n.size();i++)
    {
        for(int j=1;j<=m.size();j++)
        {
            if(n[i-1] == m[j-1]) d[i][j] = d[i-1][j-1]+1;
            else if(n[i-1]!=m[j-1]) d[i][j] = max(d[i-1][j],d[i][j-1]);
        }
    }
    cout<<d[n.size()][m.size()];
}