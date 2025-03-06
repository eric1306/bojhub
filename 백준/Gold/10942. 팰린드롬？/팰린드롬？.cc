//Authored by: prid1306
#include <iostream>
using namespace std;
int n,m;
int p[2001];
int d[2001][2001]; //d[i][j] : i~j까지의 수가 팰린드롬인가?
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) d[i][i] = 1;
    for(int i=n;i>=1;i--)
    {
        for(int j=n;j>=i;j--)
        {
            if(p[i] == p[j])
            {
                if(i == j || i== j-1) d[i][j] = 1;
                else d[i][j] = d[i+1][j-1];
            }
        }
    }
    cin>>m;
    while(m--)
    {
        int f,b;
        cin>>f>>b;
        cout<<d[f][b]<<'\n';
    }
}