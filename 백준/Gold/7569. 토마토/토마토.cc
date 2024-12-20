#include <iostream>
#include <utility>
#include <queue>

#define x first
#define y second

using namespace std;
int board[102][102][102];
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n,h,ans = 0;
    cin>>m>>n>>h;
    queue<pair<int,pair<int,int>>> q;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>board[k][j][i];
                if(board[k][j][i] == 1) q.push({k,{j,i}});
            }
        }
    }
    while(!q.empty()){
        int r = q.size();
        for(int j = 0;j<r;j++){
            pair<int,pair<int,int>> p = q.front();
            q.pop();
            for(int i=0;i<6;i++){
                int nx = p.x + dx[i];
                int ny = p.y.x + dy[i];
                int nz = p.y.y + dz[i];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >=h) continue;
                if(board[nx][ny][nz] !=0) continue;
                q.push({nx,{ny,nz}});
                board[nx][ny][nz] = 1;
            }
        }
        ans++;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(board[k][j][i] == 0){
                    cout<<"-1";
                    return 0;
                }
            }
        }
    }
    cout<<ans-1;
}