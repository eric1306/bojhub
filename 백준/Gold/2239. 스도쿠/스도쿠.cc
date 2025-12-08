// Authored by: prid1306
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
const int ROW = 9;
const int COL = 9;
const int BLOCK_OFFSET = 3; //3 * 3 블럭 이중 for문을 위한 offset
string board[ROW];
bool row[10][10]; //row[i][j]: i번째 행에 j수가 존재하는가?
bool col[10][10]; // col[i][j]: i번째 열에 j 수가 존재하는가?
bool block[10][10]; //block[(i/3)*3 + j][k] : (i/3)*3 + j 번째 블록에 숫자 k가 존재하는가?

int GetBlock(int i, int j)
{
    return (i/3)*3 + j/3;
}
bool bt(int cnt)
{
    //cout<<"cnt: "<<cnt<<'\n';
    if(cnt == 81)
    {
        for(int i=0;i<ROW;i++){
            cout<<board[i]<<'\n';
        }
        return true;
    }

    int x = cnt / ROW;
    int y = cnt % COL;
    if(board[x][y] != '0')
    {
        return bt(cnt + 1);
    }
    else
    {
        for(int i=1;i<=9;i++)
        {
            if(row[x][i] == 0 && col[y][i] == 0 && block[GetBlock(x, y)][i] == 0)
            {
                row[x][i] = col[y][i] = block[GetBlock(x, y)][i] = true;
                board[x][y] = i + '0';
                //cout<<"board["<<x<<"]["<<y<<"]: "<<board[x][y]<<'\n';
                if(bt(cnt + 1))
                {
                    return true;
                }
                board[x][y] = '0';
                row[x][i] = col[y][i] = block[GetBlock(x, y)][i] = false;
            }
        }
    }

    return false;
}

int main(){
    FASTIO;
    for(int i=0;i<ROW;i++)
    {
        cin>>board[i];
        for(int j=0;j<COL;j++)
        {
            if(board[i][j] != '0')
            {
                //만약 i, j번째 칸에 수가 있다면
                // i행, j 열, (i/3)*3, (j/3)*3을 둘러싸는 3*3 크기의 블럭에는 그 수가 절대로 들어가면 안된다.
                row[i][board[i][j] - '0'] = true;
                col[j][board[i][j] - '0'] = true;
                block[GetBlock(i, j)][board[i][j] - '0'] = true;
            }
        }
    }
    bt(0);
}