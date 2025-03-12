//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second

int g[101][101];
int visit[101][101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        cin>>g[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(g[j][i] == 1 && g[i][k] == 1) g[j][k] = 1;
            }
        }   
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            cout<<g[i][j]<<' ';
        }
        cout<<'\n';
    }
}