//Authored by : prid1306
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
string arr[1001];
int d[1001][1001];

void printar(){
    cout<<"---------------------"<<'\n';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            cout<<d[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"---------------------"<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i-1][j-1] == '1')
            {
                d[i][j] = min(d[i-1][j],min(d[i-1][j-1],d[i][j-1])) + 1;
            }
        }
    }
    //printar();
    int max = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(max < d[i][j]) max = d[i][j];
        }
    }
    cout<<max*max;
}