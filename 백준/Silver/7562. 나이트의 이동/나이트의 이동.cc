#include <iostream>
#include <utility>
#include <queue>

#define x first
#define y second

using namespace std;
int board[301][301];
int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, l;
    cin>>tc;
    while(tc--)
    {
        cin>>l;
        pair<int,int> now, dest;
        cin>>now.x>>now.y;
        cin>>dest.x>>dest.y;
        for(int i=0;i<l;i++)
        {
            fill(board[i],board[i]+301,-1);
        }
        queue<pair<int,int>> q;
        q.push(now);
        board[now.x][now.y] = 0;
        while(board[dest.x][dest.y]==-1)
        {
            pair<int,int> p = q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if(nx < 0 || nx >= l || ny < 0 || ny >= l ) continue;
                if(board[nx][ny]!=-1) continue;
                q.push({nx,ny});
                board[nx][ny] = board[p.x][p.y]+1;
            }
        }
        cout<<board[dest.x][dest.y]<<'\n';
    }
}