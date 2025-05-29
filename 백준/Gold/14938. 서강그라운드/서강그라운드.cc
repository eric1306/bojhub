//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int d[101][101];
int nxt[101][101];
int ItemNum[31];
const int INF = 0x3f3f3f3f;
int n,m,r;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>r;
    for(int i=1;i<=n;i++){
        fill(d[i],d[i]+1+n,INF);
    }
    for(int i=1;i<=n;i++){
        cin>>ItemNum[i];
    }
    
    for(int i=1;i<=r;i++){
        int a,b,l;
        cin>>a>>b>>l;
        d[a][b] = min(d[a][b],l);
        nxt[a][b] = b;
        d[b][a] = min(d[b][a],l);
        nxt[b][a] = a;
    }
    for(int i=1;i<=n;i++){
        d[i][i] = 0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    long long ans = 0;
    for(int i=1;i<=n;i++){
        int tmp = ItemNum[i];
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(d[i][j] <= m) tmp+=ItemNum[j];
        }
        if(ans < tmp) ans = tmp;
    }
    cout<<ans;
}