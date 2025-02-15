#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

//x,,y: 시작점, d방향 g세대
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int board[102][102];
int n,x,y,d,g;

int findbox(){
    int cnt = 0;
    for(int i=0;i<102;i++){
        for(int j=0;j<102;j++){
            if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) cnt++;
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        cin>>x>>y>>d>>g;
        int nx = x + dx[d];
        int ny = y + dy[d];
        board[y][x] = 1;
        board[ny][nx] = 1;
        vector<int> v;
        v.push_back(d);
        while(g--){
            int tmp = v.size();
            queue<pair<int,int>> q;
            int flag = 1;
            for(int i=tmp-1;i>=0;i--){
                int td = v[i];
                nx = nx + dx[(td+1)%4];
                ny = ny + dy[(td+1)%4];
                if(nx < 0 || nx >= 102 || ny < 0 || ny >= 102){
                    flag = 0;
                    break;
                }
                q.push({nx,ny});
                int newdir = (td+1)%4;
                v.push_back(newdir);
            }
            if(flag){
                while(!q.empty()){
                    pair<int,int> p = q.front();q.pop();
                    board[p.second][p.first] = 1;
                }
            }
        }
    }
    cout<<findbox();
}
