#include <iostream>
#include <deque>
using namespace std;
deque<pair<int,char>> d;
deque<pair<int,int>> snake;
#define x first
#define y second
#define WALL 1
#define APPLE 2
#define SNAKE 9
/*1은 벽, 2는 사과, 9는 snake*/
int board[101][101];
/*반시계(왼쪽)으로 동, 북, 서, 남*/
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int dir = 0;
int n;
bool OOB(int x, int y)
{
    return (x < 0 || x >=n || y < 0 || y>=n);
}
void printarr()
{
    cout<<"-----------------"<<'\n';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j];
        }
        cout<<'\n';
    }
    cout<<"-----------------"<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, l,x,y,t,time = 0;
    cin>>n>>k;
    for(int i=0;i<k;i++){ /*apple location*/
        cin>>x>>y;
        board[x-1][y-1]=APPLE;
    }
    snake.push_back({0,0});
    board[0][0] = SNAKE;
    cin>>t;
    while(t--)
    {
        int time;
        char dir;
        cin>>time>>dir;
        d.push_back({time,dir});
    }
    int stx = 0;
    int sty = 0;
    //printarr();
    while(true)
    {
        int nx = stx + dx[dir];
        int ny = sty + dy[dir];
        //cout<<nx<<ny<<'\n';
        if(OOB(nx,ny)||board[nx][ny] == 1 || board[nx][ny] == 9) break;
        snake.push_front({nx,ny});
        if(board[nx][ny] != 2)
        {
            board[snake.back().x][snake.back().y] = 0;
            snake.pop_back();
        }
        board[nx][ny] = 9;
        stx = nx;sty=ny;
        //printarr();
        time++;
        //cout<<"time: "<<time<<'\n';
        if(time == d.front().x) //change dir
        {
            if(d.front().y == 'D')
            {
                if(dir == 0) dir = 3;
                else dir--;
            }
            else
            {
                dir = (dir+1)%4;
            }
            d.pop_front();
        }
    }
    cout<<time+1;
}