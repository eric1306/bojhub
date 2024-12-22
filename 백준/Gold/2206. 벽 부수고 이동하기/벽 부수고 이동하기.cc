#include <iostream>
#include <utility>
#include <queue>
#include <string>

#define x first
#define y second

using namespace std;

string board[1001];
//벽 안부수고 방문했는지 체크
bool visit[1001][1001];
// 벽부수는 루트가 방문했는지 체크
bool bvisit[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>board[i];
    
    if(n==1 & m == 1)
    {
        cout<<1;
        return 0;
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},1});
    visit[0][0] = 1;
    while(!q.empty())
    {
        pair<pair<int,int>,int> p = q.front();
        q.pop();
        for(int ix=0; ix < 4;ix++)
        {
            int nx = p.x.x + dx[ix];
            int ny = p.x.y + dy[ix];
            //cout<<"pxy: "<<p.x.x<<" "<<p.x.y<<" nxy: "<<nx<<" "<<ny<<'\n';
            if(nx == n-1 && ny == m-1){
                cout<<p.y+1<<'\n';
                return 0;
            }
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '1')
            {
                //cout<<"1"<<visit[nx][ny]<<bvisit[nx][ny]<<visit[p.x.x][p.x.y]<<bvisit[p.x.x][p.x.y]<<'\n';
                if(!visit[nx][ny] && !bvisit[nx][ny] && visit[p.x.x][p.x.y]) {
                    q.push({{nx,ny},p.y+1});
                    bvisit[nx][ny] = 1;
                }
            }
            else if(board[nx][ny] == '0')
            {
                if(bvisit[p.x.x][p.x.y] != 0){
                    //cout<<"2"<<visit[nx][ny]<<bvisit[nx][ny]<<visit[p.x.x][p.x.y]<<bvisit[p.x.x][p.x.y]<<'\n';
                    if(!bvisit[nx][ny]) q.push({{nx,ny},p.y+1});
                    bvisit[nx][ny] = 1;
                }
                if(visit[p.x.x][p.x.y]!=0){
                    //cout<<"3"<<visit[nx][ny]<<bvisit[nx][ny]<<visit[p.x.x][p.x.y]<<bvisit[p.x.x][p.x.y]<<'\n';
                    if(!visit[nx][ny]) q.push({{nx,ny},p.y+1});
                    visit[nx][ny] = 1;
                }
            }
        }
    }    
    cout<<-1;
}
