#include <iostream>
#include <utility>
#include <queue>

#define x first
#define y second

using namespace std;
//상하좌우
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
//기존 보드판
string board[1001];
//불 dist
int Fire[1001][1001];
//상근 dist
int Sg[1001][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int w,h;
        //@, 상근이 시작 위치
        pair<int,int> SgStart;
        //불들의 위치 모여있는 queue
        queue<pair<int,int>> FireQ;
        cin>>w>>h;
        //보드판 초기화
        fill(board,board+1000,"");
        for(int i = 0;i<h;i++)
        {
            fill(Fire[i],Fire[i]+1000,-1);
            fill(Sg[i],Sg[i]+1000, -1);
        }
        for(int i = 0;i<h;i++)
        {
            cin>>board[i];
            for(int j=0;j<board[i].length();j++)
            {
                
                if(board[i][j] == '*'){
                    FireQ.push({i,j});
                    Fire[i][j] = 0;
                }
                if(board[i][j] == '@')
                {
                    SgStart = make_pair(i,j);
                }
            }
        }
        
        //불 bfs
        while(!FireQ.empty())
        {
            pair<int,int> p = FireQ.front();
            FireQ.pop();
            for(int ix = 0;ix<4;ix++)
            {
                int nx = p.x + dx[ix];
                int ny = p.y + dy[ix];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(Fire[nx][ny] != -1||board[nx][ny] == '#' || board[nx][ny] == '*') continue;
                FireQ.push({nx,ny});
                Fire[nx][ny] = Fire[p.x][p.y]+1;
            }
        }

        //상근이 탈출 BFS
        bool flag = false;
        queue<pair<int,int>> q;
        q.push(SgStart);
        Sg[SgStart.x][SgStart.y] = 0;
        while(!q.empty() && !flag)
        {
            pair<int,int> p = q.front();
            q.pop();
            for(int ix = 0;ix<4;ix++)
            {
                int nx = p.x + dx[ix];
                int ny = p.y + dy[ix];
                //탈출
                if(nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    cout<<Sg[p.x][p.y]+1<<'\n';
                    flag = true;
                    break;
                }
                if(board[nx][ny] == '#'||board[nx][ny] =='*') continue;
                if(Sg[nx][ny]!= -1 || (Fire[nx][ny] != -1 && Sg[p.x][p.y]+1 >= Fire[nx][ny])) continue;
                q.push({nx,ny});
                Sg[nx][ny] = Sg[p.x][p.y]+1;
            }
        }
        if(!flag) cout<<"IMPOSSIBLE"<<'\n';
    }
}