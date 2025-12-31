// Authored by: prid1306
#include <iostream>
#include <string>
#include <stack>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
#define y first
#define x second

using namespace std;
using pii = pair<int,int>;
enum{
    U = 0,
    D,
    L,
    R
};
//위, 아래, 왼, 오
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n,m;
string board[1001];
int status[1001][1001];
int ans;
int main(){
    FASTIO;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>board[i];
        fill(status[i], status[i] + m, 0);
    }
    if(n == 1 && m == 1){
        cout<<1; return 0;
    }
    //i in 0~n j in 0~m
    /*
    뭔~가 텀 프로젝트를 활용하면 될 것 같은데?
    */
    int cnt = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(status[i][j]) continue;
            //cout<<"("<<i<<", "<<j<<") is empty!\n";
            stack<pii> s;
            s.emplace(i, j);
            while(!s.empty())
            {
                auto p = s.top(); s.pop();
                //cout<<p.y<<" "<<p.x<<'\n';
                status[p.y][p.x] = cnt;
                int ny,nx;
                if(board[p.y][p.x] == 'U')
                {
                    ny = p.y + dy[0];
                    nx = p.x + dx[0];
                }
                else if(board[p.y][p.x] == 'D')
                {
                    ny = p.y + dy[1];
                    nx = p.x + dx[1];
                }
                else if(board[p.y][p.x] == 'L')
                {
                    ny = p.y + dy[2];
                    nx = p.x + dx[2];
                }
                else
                {
                    ny = p.y + dy[3];
                    nx = p.x + dx[3];
                }
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if(status[ny][nx])
                {
                    //cout<<"status: "<<status[ny][nx]<<' '<<cnt<<'\n';
                    if(status[ny][nx] == cnt) //이번 분기에 방문했던 칸을 재방문 -> SAFE ZONE
                    {
                        ans++;
                        break;
                    }
                    else
                    {
                        continue; //지난 분기에 방문했던 칸 재방문 -> NOT SAFE ZONE
                    }
                }
                s.emplace(ny, nx);
            }
            cnt++;
        }
    }
    cout<<ans;
}