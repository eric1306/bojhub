// Authored by: prid1306
#include <iostream>
#include <string>
#include <stack>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
//위, 아래, 왼, 오
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n,m;
string board[1001];
int status[1001][1001];
int ans;
int main(){
    FASTIO;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>board[i];
        fill(status[i], status[i] + m, 0);
    }
    if(n == 1 && m == 1){
        cout<<1; return 0;
    }
    int cnt = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(status[i][j]) continue;
            int ny = i,nx = j;
            while(1)
            {
                status[ny][nx] = cnt;

                switch(board[ny][nx])
                {
                    case 'U': ny--; break;
                    case 'D': ny++; break;
                    case 'L': nx--; break;
                    case 'R': nx++; break;
                }
                if(status[ny][nx]){
                    if(status[ny][nx] == cnt){
                        ans++;
                    }
                    break;
                }
            }
            cnt++;
        }
    }
    cout<<ans;
}