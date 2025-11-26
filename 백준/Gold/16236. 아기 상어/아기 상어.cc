// Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

struct Pos{
    int x;
    int y;
};
int n,ans;
int a[21][21];
int dist[21][21];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
Pos BSPos;
int BSLevel = 2;
int EatFishAmount = 0;

void BFS(){
    for(int i=0;i<21;i++){
        fill(dist[i], dist[i] + 21, -1);
    }
    queue<Pos> q; //position, dist
    bool visit[21][21];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) { visit[i][j] = false;}
    visit[BSPos.x][BSPos.y] = true;
    q.push(BSPos);
    dist[BSPos.x][BSPos.y] = 0;
    while(!q.empty())
    {
        auto p = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visit[nx][ny] || a[nx][ny] > BSLevel) continue;
            visit[nx][ny] = true;
            dist[nx][ny] = dist[p.x][p.y] + 1;
            q.push({nx, ny});
        }
    }
}

class CMP
{
public:
    bool operator()(pair<Pos, int> a, const pair<Pos, int> b)
    {
        if(a.second > b.second) return true;
        else if(a.second == b.second){
            if(a.first.x > b.first.x) return true;
            else if(a.first.x == b.first.x){
                if(a.first.y > b.first.y) return true;
            }
        }
        return false;
    }
};

int main(){
    FASTIO;
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        cin>>a[i][j];
        if(a[i][j] == 9) 
            BSPos = {i, j};
    }

    while(true) //사냥할 수 있는 먹이가 있을 때 400
    {
        BFS();
        //먹이가 1개라면 이거 선택 
        //먹이가 2개 이상이라면 가장 거리가 짧은 먹이 중 가장 위, 왼쪽에 있는 걸 선택 400
        //가장 가까운 먹이 찾기
        Pos minPos = {};
        priority_queue<pair<Pos, int>, vector<pair<Pos, int>>, CMP> pq;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            if(a[i][j] == 0 || a[i][j] == 9 || a[i][j] >= BSLevel || dist[i][j] == -1) continue;
            pq.push({{i, j}, dist[i][j]});
        }
        if(pq.empty()) break;
        minPos = pq.top().first;
        
        //cout<<"minPos : "<<minPos.x<<' '<<minPos.y<<'\n';
        //해당 먹이까지 갈 수 있는지 판단 400
        int dist = pq.top().second;
        //cout<<"dist: "<<dist<<'\n';
        if(dist == 0) break;  //안된다면 break
        
        //된다면 이동시키고 시간 + 해주기
        ans += dist;
        //해당 자리 0으로 바꿔버리고(먹었다는 표시) continue;
        a[BSPos.x][BSPos.y] = 0;
        BSPos = minPos;
        a[BSPos.x][BSPos.y] = 9;
        EatFishAmount++;
        if(EatFishAmount == BSLevel)
        {
            EatFishAmount = 0; BSLevel++;
        }
        //cout<<"ans: "<<ans<<'\n';
    }
    cout<<ans<<'\n';
}