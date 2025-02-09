#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int n,m;
enum
{
    EMPTY = 0,
    WALL = 1,
    VIRUS = 2
};
int board[10][10];
int board2[10][10];
int visit[10][10];
queue<pair<int,int>> virus;
vector<pair<int,int>> empty_space;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ans=0;
void copy_board(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            board2[i][j]=board[i][j];
}
void bfs(){
    queue<pair<int,int>> q=virus;
    while(!q.empty()){
        auto cur=q.front();q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.first+dx[dir];
            int ny=cur.second+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m || visit[nx][ny]==1)continue;
            if(board2[nx][ny]==EMPTY){
                board2[nx][ny]=VIRUS;
                q.push({nx,ny});
                visit[nx][ny]=1;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(board2[i][j]==EMPTY)
                cnt++;
    ans=max(ans,cnt);
}
int main(){
    ios::sync_with_stdio(0);

    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
            if(board[i][j]==VIRUS)
                virus.push({i,j});
            else if(board[i][j]==EMPTY)
                empty_space.push_back({i,j});
        }
    }
    vector<int> v;
    for(int i=0;i<empty_space.size()-3;i++)
        v.push_back(0);
    for(int i=0;i<3;i++)
        v.push_back(1);

    do{
        copy_board();
        for(int i=0;i<10;i++)
            fill(visit[i],visit[i]+10,0);
        for(int i=0;i<empty_space.size();i++){
            if(v[i]==1)
                board2[empty_space[i].first][empty_space[i].second]=WALL;
        }
        bfs();

    }while(next_permutation(v.begin(),v.end()));

    cout<<ans;
}