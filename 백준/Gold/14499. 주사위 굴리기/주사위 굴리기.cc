#include <iostream>
#include <algorithm>
using namespace std;

int n,m,x,y,k,op;
int board[21][21];

//순서대로 위: 0, 아래: 1, 동: 2, 서: 3, 북: 4, 남: 5
int dice[6] = {0,0,0,0,0,0};

void east(){ /*동쪽으로 굴리기*/
    int tmp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[1];
    dice[1] = dice[2];
    dice[2] = tmp;
}
void west(){ /*서쪽으로 굴리기*/
    int tmp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[1];
    dice[1] = dice[3];
    dice[3] = tmp;
}
void north(){ /*북쪽으로 굴리기*/
    int tmp = dice[0];
    dice[0] = dice[5];
    dice[5] = dice[1];
    dice[1] = dice[4];
    dice[4] = tmp;
}
void south(){ /*남쪽으로 굴리기*/
    int tmp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[1];
    dice[1] = dice[5];
    dice[5] = tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>x>>y>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
        }
    }
    while(k--){
        cin>>op;
        if(op == 1)//east
        {
            if(y == m-1) continue;
            east();
            y++;
            if(board[x][y] == 0){
                board[x][y] = dice[1];
            }
            else{
                dice[1] = board[x][y];
                board[x][y] = 0;
            }
        }
        else if(op == 2)//west
        {
            if(y == 0) continue;
            west();
            y--;
            if(board[x][y] == 0){
                board[x][y] = dice[1];
            }
            else{
                dice[1] = board[x][y];
                board[x][y] = 0;
            }
        }
        else if(op == 3)//north
        {
            if(x == 0) continue;
            north();
            x--;
            if(board[x][y] == 0){
                board[x][y] = dice[1];
            }
            else{
                dice[1] = board[x][y];
                board[x][y] = 0;
            }
        }
        else//4, south
        {
            if(x == n-1) continue;
            south();
            x++;
            if(board[x][y] == 0){
                board[x][y] = dice[1];
            }
            else{
                dice[1] = board[x][y];
                board[x][y] = 0;
            }
        }
        cout<<dice[0]<<'\n';
    }
}