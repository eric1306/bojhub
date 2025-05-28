//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int D[102][102];
int n,m,a,b,c;
const int MAXNUM = 10'000'001;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++){
        fill(D[i], D[i] + n, MAXNUM);
    }
    for(int i=0;i<n;i++){
        D[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(D[a-1][b-1] > c){
            D[a-1][b-1] = c;
        }
    }

    for(int k=0;k<n;k++){
        for(int s=0;s<n;s++){
            for(int t=0;t<n;t++){
                if(D[s][t] == 0) continue;
                D[s][t] = min(D[s][t],D[s][k] + D[k][t]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(D[i][j] == MAXNUM)
                cout<<0<<' ';
            else
                cout<<D[i][j]<<' ';
        }
        cout<<'\n';
    }
}