#include <iostream>
#include <utility>
#include <queue>

#define x first
#define y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dist[52][52];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<52;i++) fill(dist[i],dist[i]+52,0);
        int n,m,k,row,col,ans = 0;
        queue<pair<int,int>> q;
        cin>>n>>m>>k;
        for(int i=0;i<k;i++)
        {
            cin>>row>>col;
            dist[row][col] = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dist[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int> p = q.front();
                        q.pop();
                        for(int l=0;l<4;l++){
                            int nx = p.x + dx[l];
                            int ny = p.y + dy[l];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(dist[nx][ny] !=1) continue;
                            dist[nx][ny] = 0;
                            q.push({nx,ny});
                        }
                    }
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}