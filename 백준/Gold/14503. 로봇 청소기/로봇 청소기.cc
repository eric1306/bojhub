#include <iostream>
using namespace std;

#define x first
#define y second

int n,m,stx,sty,dir,ans;

/*순서대로 북, 동, 남, 서*/
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int board[53][53];

bool OOB(int posX, int posY)
{
    if(posX < 0 || posX >=n || posY < 0 || posY >= m)
        return false;
    if(board[posX][posY] == 1) /*wall*/
        return false;

    return true;
}

bool isZero(int posX, int posY)
{
    for(int i=0;i<4;i++)
    {
        int nx = posX + dx[i];
        int ny = posY + dy[i];
        if(board[nx][ny] == 0) 
            return true;
    }
    return false;
}
void nextdir()
{
    if(dir == 0) dir = 3;
    else if(dir == 3) dir = 2;
    else if(dir == 2) dir = 1;
    else dir = 0;
}

void bfs(){
    while(true)
    {
        if(board[stx][sty] == 0)/*현재 칸이 청소되지 않았다면*/
        {
            board[stx][sty] = 9;
            ans++;
            //cout<<"clean ("<<stx<<","<<sty<<") / ans: "<<ans<<'\n';
        }
        if(!isZero(stx,sty))/*청소되지 않은 빈 칸이 없다면*/
        {
            if(OOB(stx+dx[(dir+2)%4],sty+dy[(dir+2)%4])) /*후진 가능하다면*/
            {
                stx+=dx[(dir+2)%4];
                sty+=dy[(dir+2)%4];
                //cout<<"bbakku: ("<<stx<<","<<sty<<")"<<'\n';
                continue;
            }
            else return;
        }
        else
        {
            nextdir();
            int nx = stx + dx[dir];
            int ny = sty + dy[dir];
            if(board[nx][ny] == 0)
            {
                stx = nx;
                sty = ny;
                //cout<<"move to ("<<stx<<","<<sty<<")"<<'\n';
            }
            continue;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>stx>>sty>>dir;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        cin>>board[i][j];
    }
    bfs();
    cout<<ans;
}