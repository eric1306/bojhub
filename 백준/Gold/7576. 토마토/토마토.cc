#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std;
#define x first
#define y second

int board[1002][1002];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int day = 0;
    cin>>n>>m;
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 1) q.push({i,j});
        }
    }
    //하루가 지나는 것을 파악하는 방법?
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(board[nx][ny] != 0) continue;
            q.push({nx,ny});
            board[nx][ny] = board[p.x][p.y]+1;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 0) {
                cout<<-1;
                return 0;
            }
            if(day < board[i][j]) day = board[i][j];
        }
    }
    cout<<day-1;
}