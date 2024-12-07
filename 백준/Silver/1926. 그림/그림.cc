#include <iostream>
#include <utility>
#include <queue>

#define X first
#define Y second

int board[502][502];
bool visit[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;
int main(){
    int n,m,num = 0,maxSize = 0;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            queue<pair<int,int>> q;
            int qsize = 0;

            if(board[i][j] == 1 && !visit[i][j]){
                visit[i][j] = 1;
                q.push({i,j});
                qsize++;

                while(!q.empty()){
                    pair<int,int> p = q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = p.X + dx[k];
                        int ny = p.Y + dy[k];
                        if(nx <0 || nx >= n || ny <0 || ny >= m) continue;
                        if(visit[nx][ny] || board[nx][ny] != 1) continue;
                        visit[nx][ny] = 1;
                        q.push({nx,ny});
                        qsize++;
                    }
                }
                num++;
                if(maxSize < qsize) maxSize = qsize;
            }
        }
    }
    cout<<num<<'\n'<<maxSize;
}