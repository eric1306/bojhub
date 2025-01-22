#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n,m;
int ans = 0;

int board[10][10];
int board2[10][10];
vector<pair<int,int>> v;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

#define x first
#define y second

void duplicate_board(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            board2[i][j] = board[i][j];
        }
    }
}

void fillboard(int type, int share ,int nx, int ny)
{
    int val = share % 4;
    while(true)
    {
        nx += dx[val];
        ny += dy[val];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) break; /*잘못 들어온거임*/
        if(board2[nx][ny] == 6) break;
        if(board2[nx][ny]!=0) continue;
        board2[nx][ny] = type;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ans = n*m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
            if(board[i][j]!=6 && board[i][j]!=0)
                v.push_back({i,j});
        }
    }
    int tmp = v.size();
    
    //0~4^v.size()-1
    for(int i=0;i<(1<<2*tmp);i++)
    {
        duplicate_board();

        int cnt = tmp > 0 ? 1<<2*(tmp-1) : 0;

        vector<int> vec;

        int tmpi = i;
        int tmpdiv = tmpi;

        while(cnt!=0){
            tmpdiv = tmpdiv/cnt;
            vec.push_back(tmpdiv);
            tmpdiv = tmpi%cnt;
            cnt/=4;
        }

        int idx = 0;
        int vsize = vec.size();
        while(idx < vsize)
        {

            pair<int,int> p = v.at(idx);
            int temp = vec.at(idx);
            
            int boardspot = board2[p.x][p.y];
            if(boardspot == 1)
            {
                fillboard(1,temp,p.x,p.y);
            }
            else if(boardspot == 2)
            {
                fillboard(2,temp,p.x,p.y);
                fillboard(2,temp+2,p.x,p.y);
            }
            else if(boardspot == 3)
            {
                fillboard(3,temp,p.x,p.y);
                fillboard(3,temp+3,p.x,p.y);
            }
            else if(boardspot == 4)
            {
                fillboard(4,temp,p.x,p.y);
                fillboard(4,temp+2,p.x,p.y);
                fillboard(4,temp+3,p.x,p.y);
            }
            else if(boardspot == 5)
            {
                fillboard(5,temp,p.x,p.y);
                fillboard(5,temp+1,p.x,p.y);
                fillboard(5,temp+2,p.x,p.y);
                fillboard(5,temp+3,p.x,p.y);
            }
            ++idx;
            if(vec.size() == 0) break;
        }

        int zerocount=0;
        //print_board();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board2[i][j] == 0) ++zerocount;
            }
        }
        if(ans > zerocount) ans = zerocount;
    }
    cout<<ans;
}