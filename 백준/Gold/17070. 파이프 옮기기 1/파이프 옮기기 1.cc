// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using pii = pair<int,int>;
#define x first
#define y second
int n;
int board[16][16];
int d[20][20][3];

int main(){
    FASTIO;
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>board[i][j];
    for(int i = 1; i<n-1;i++){
        if(board[0][i] == 1) break;
        d[0][i][0] = 1;
        d[0][i][1] = 0;
        d[0][i][2] = 0;
    }
    for(int i=1;i<n;i++){
        for(int j=2;j<n;j++){
            if(board[i][j] != 1){
                d[i][j][0] = d[i][j-1][0] + d[i][j-1][2];
                d[i][j][1] = d[i-1][j][1] + d[i-1][j][2];
            }
            if(board[i][j] != 1 && board[i-1][j] != 1 && board[i][j-1] != 1)
            {
                d[i][j][2] = d[i-1][j-1][0] + d[i-1][j-1][1] + d[i-1][j-1][2];
            }
        }
    }
    cout<<d[n-1][n-1][0] + d[n-1][n-1][1] + d[n-1][n-1][2];
}