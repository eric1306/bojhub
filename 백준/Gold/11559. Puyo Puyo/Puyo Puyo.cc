#include <iostream>
#include <utility>
#include <queue>

using namespace std;

#define ROW 12
#define COL 6

#define x first
#define y second

string board[ROW];
int visit[12][6];
int cnt = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>> deleteq;

bool OOB(int nx, int ny){
    return nx  < 0 || nx >= 12 || ny < 0 || ny >=6;
}

bool check(){
    /*R, Y, G*/
    int arr[3] = {0,0,0};
    
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(!visit[i][j] && board[i][j]!='.'){
                visit[i][j] = 1;
                queue<pair<int,int>> q;
                queue<pair<int,int>> tmp;
                tmp.push({i,j});
                q.push({i,j});
                while(!q.empty()){
                    pair<int,int> p = q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = p.x + dx[k];
                        int ny = p.y + dy[k];
                        if(OOB(nx,ny) || visit[nx][ny] || board[nx][ny]!=board[p.x][p.y]) continue;
                        visit[nx][ny] = 1;
                        tmp.push({nx,ny});
                        q.push({nx,ny});
                    }
                }
                if(tmp.size() >= 4){
                    while(!tmp.empty()){
                        //cout<<"hi"<<'\n';
                        deleteq.push(tmp.front());
                        tmp.pop();
                    }
                }
                else{
                    while(!tmp.empty()) tmp.pop();
                }
            }
        }
    }
    if(!deleteq.empty()) return true;
    else return false;
}

void DownPuyo(){
    for(int j=0;j<COL;j++){
        int idx = ROW-1;
        for(int i=ROW-1;i>=0;i--){
            if(board[i][j] == '.') continue;
            if(board[idx][j] == '.'){
                board[idx--][j] = board[i][j];
                board[i][j] = '.';
            }else if (idx > 0){
                idx--;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<ROW;++i) cin>>board[i];
    
    bool flag = false;
    while(check()){
        while(!deleteq.empty()){
            pair<int,int> p = deleteq.front();
            deleteq.pop();
            board[p.x][p.y] = '.';
        }
        cnt++;
        DownPuyo();
        
        for(int i=0;i<ROW;i++) fill(visit[i],visit[i]+6,false);
    }
    cout<<cnt<<'\n';
}