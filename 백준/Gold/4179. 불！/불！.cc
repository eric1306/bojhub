#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std;

#define x first
#define y second

string board[1001];
int fireDst[1001][1001];
int jh[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0, 1, 0, -1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool escape = false;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>board[i];
    for(int i=0;i<n;i++){
        fill(fireDst[i], fireDst[i]+m,-1);
        fill(jh[i], jh[i]+m,-1);
    }
    queue<pair<int,int>> q;
    //불 찾기
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 'F') {
                q.push({i,j});
                fireDst[i][j] = 0;
            }
        }
    }
    //불 BFS
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(fireDst[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            fireDst[nx][ny] = fireDst[p.x][p.y]+1;
            q.push({nx,ny});
        }
    }
    //지훈 찾기
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 'J') {
                q.push({i,j});
                jh[i][j] = 0;
            }
        }
    }
    //지훈 BFS
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                cout<<jh[p.x][p.y]+1;
                return 0;
            }
            if(jh[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(fireDst[nx][ny]!=-1 && jh[p.x][p.y] + 1 >= fireDst[nx][ny]) continue;
            jh[nx][ny] = jh[p.x][p.y] + 1;
            q.push({nx,ny});
        }
    }
    cout<<"IMPOSSIBLE";
}