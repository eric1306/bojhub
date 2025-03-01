//Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <string>

#define MODENUM 1'000'000'000
using namespace std;

int n;
int d[101][10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<10;i++) d[1][i] = 1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(j!=0) d[i][j] += d[i-1][j-1];
            if(j!=9) d[i][j] += d[i-1][j+1];
            d[i][j]%=MODENUM;
        }
    }
    
    long long max = 0;
    for(int i=0;i<10;i++){
        max += d[n][i];
    }
    max%=MODENUM;
    cout<<max;
}