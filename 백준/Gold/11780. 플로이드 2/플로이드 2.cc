//Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int D[102][102];
int nxt[102][102];
int n,m,a,b,c;
const int MAXNUM = 10'000'001;
const int INF = 0x3f3f3f3f; //int overfolw 발생 방지로 ox7f7f7f7f라 설정하지 않음.
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
        D[a-1][b-1] = min(D[a-1][b-1], c);
        nxt[a-1][b-1] = b-1;
    }
    for(int k=0;k<n;k++){
        for(int s=0;s<n;s++){
            for(int t=0;t<n;t++){
                if(D[s][t] > D[s][k] + D[k][t]){
                    D[s][t] = D[s][k] + D[k][t];
                    nxt[s][t] = nxt[s][k];
                }
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
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        if(D[i][j] == 0 || D[i][j] == MAXNUM){
            cout<<0<<'\n';
            continue;
        }
        vector<int> path;
        int st = i;
        while(st!=j){
            path.push_back(st+1);
            st = nxt[st][j];
        }
        path.push_back(j+1);
        cout<<path.size()<<' ';
        for(auto x : path) cout<<x<<' ';
        cout<<'\n';
    }
}