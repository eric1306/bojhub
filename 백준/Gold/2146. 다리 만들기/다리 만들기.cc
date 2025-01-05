#include <iostream>
#include <utility>
#include <queue>
#include <tuple>

#define x first
#define y second

using namespace std;

int sector[101][101];
int n,cnt = 2;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int xPos, int yPos){
    queue<pair<int,int>> q;
    q.push({xPos,yPos});
    sector[xPos][yPos] = cnt;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(sector[nx][ny] == 0 || sector[nx][ny]!=1) continue;
            sector[nx][ny] = cnt;
            q.push({nx,ny});
        }
    }
}
int Path_bfs(int xPos, int yPos){
    int visit[101][101];
    for(int i=0;i<n;i++) fill(visit[i],visit[i]+n,false);
    queue<tuple<int,int,int>> q;
    q.push({xPos,yPos,0});
    int nsector = sector[xPos][yPos];
    while(!q.empty()){
        tuple<int,int,int> t = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = get<0>(t) + dx[i];
            int ny = get<1>(t) + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(sector[nx][ny] == nsector || visit[nx][ny]) continue;
            if(sector[nx][ny]!=0 && sector[nx][ny]!=nsector){
                return get<2>(t);
            }
            visit[nx][ny] = true;
            q.push({nx,ny,get<2>(t)+1});
            //cout<<nx<<ny<<'\n';
        }
    }
    return 0;
}
bool checksector(int i,int j){
    for(int ix = 0;ix < 4; ix++){
        int nx = i + dx[ix];
        int ny = j + dy[ix];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
        if(sector[nx][ny] == 0) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int min = 2*n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>sector[i][j];
        }
    }
    //섬 구분, 이건 배열에 sector 나눠서 구현.
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(sector[i][j] &&  sector[i][j] == 1){
                bfs(i,j);
                cnt++;
            }
        }
    }
    //각 섬마다 bfs 돌려서 다음 sector로 가는 최단 거리 ans에 넣기.
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(checksector(i,j))
            {
                int len = Path_bfs(i,j);
                if(len!=0 && min > len) min = len;
            }
        }
    }
    cout<<min;
}