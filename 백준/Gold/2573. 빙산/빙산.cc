#include <iostream>
#include <utility>
#include <queue>

#define x first
#define y second

int arr[301][301];
int tmp[301][301];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

using namespace std;

int bfs(int x, int y){    
    int cnt = 0;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
        if(arr[nx][ny] == 0) cnt++;
    }
    return arr[x][y]-cnt > 0 ? arr[x][y]-cnt : 0;
}
//O(NM)
void syncarray(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = tmp[i][j];
        }
    }
}
int check_mass(){
    int cnt = 0;
    int cnt_ving = 0;
    int x,y;
    int visit[301][301];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visit[i][j] = false;
            if(arr[i][j]){
                x=i;y=j;
                cnt_ving++;
            }
        }
    }
    if(cnt_ving == 0) return 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    visit[x][y] = true;
    cnt++;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(int ix=0;ix<4;ix++){
            int nx = p.x + dx[ix];
            int ny = p.y + dy[ix];
            if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
            if(visit[nx][ny] || arr[nx][ny] == 0) continue;
            visit[nx][ny] = true;
            q.push({nx,ny});
            cnt++;
        }
    }
    if(cnt == cnt_ving) return 1;
    return 2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin>>n>>m;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            tmp[i][j] = arr[i][j];
        }
    }
    int year = 0;
    while(true){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]!=0)
                    q.push({i,j});
            }
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            tmp[p.x][p.y] = bfs(p.x,p.y);
        }
        year++;
        syncarray();
        int yearcheck = check_mass();
        if(yearcheck == 0){
            cout<<0;
            return 0;
        }else if(yearcheck == 1){
            continue;
        }else{/**/
            cout<<year;
            return 0;
        }
    }
}