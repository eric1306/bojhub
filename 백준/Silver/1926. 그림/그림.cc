#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define x first
#define y second

int board[502][502];
bool visit[502][502];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    int max = 0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<n;i++) fill(visit[i],visit[i]+m,false);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visit[i][j] && board[i][j] == 1){
                int qsize = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                visit[i][j] = 1;
                while(!q.empty()){
                    pair<int,int> p = q.front();
                    qsize++;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = p.x + dx[k];
                        int ny = p.y + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(visit[nx][ny] || board[nx][ny]!=1) continue;
                        visit[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                ans++;
                if(max < qsize) max = qsize;
            }
        }
    }
    cout<<ans<<'\n'<<max;
}