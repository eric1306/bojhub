//eric1306
//boj 10026 적록색약
#include <iostream>
#include <utility>
#include <queue>

#define x first
#define y second

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[101];
bool visit[101][101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //ans1: 적록색약X, ans2 = 적록색약
    int n,ans1=0, ans2=0;
    cin>>n;
    //board 판 입력 받기
    for(int i=0;i<n;i++){
        cin>>board[i];
    }
    //적록색약 아님.
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j]){
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    pair<int,int> p = q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = p.x + dx[k];
                        int ny = p.y + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(visit[nx][ny] || board[nx][ny]!= board[p.x][p.y]) continue;
                        q.push({nx,ny});
                        visit[nx][ny] = true;
                    }
                }
                ans1++;
            }
        }
    }
    for(int i=0;i<n;i++) fill(visit[i],visit[i]+101,false);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j]){
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    pair<int,int> p = q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = p.x + dx[k];
                        int ny = p.y + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(visit[nx][ny]) continue;
                        if(board[p.x][p.y] == 'R'||board[p.x][p.y] == 'G'){
                            if((board[nx][ny] != 'R'&&board[nx][ny] != 'G')) continue;
                        }else{
                            if(board[nx][ny]!= board[p.x][p.y]) continue;
                        }
                        q.push({nx,ny});
                        visit[nx][ny] = true;
                    }
                }
                ans2++;
            }
        }
    }

    cout<<ans1<<' '<<ans2;
}