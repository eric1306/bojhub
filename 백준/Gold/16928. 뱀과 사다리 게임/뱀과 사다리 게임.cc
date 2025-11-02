// Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,m;

int main(){
    FASTIO;
    cin>>n>>m;
    vector<int> board(101, 0);
    for(int i=1;i<101;i++){
        board[i] = i;
    }
    for(int i=0;i<n + m;i++){
        int x,y;cin>>x>>y;
        board[x] = y;
    }
    vector<int> dist(101, 0);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty())
    {
        int p = q.front();q.pop();
        for(int i=1;i<7;++i)
        {
            int pos = p + i;
            if(pos > 100) continue;
            if(dist[pos]) continue;
            dist[pos] = dist[p] + 1;
            int tmp = pos;
            if(board[pos])
                pos = board[pos];
            if(dist[pos] == 0) //차있다면 이전에 방문한 최단경로가 있다는 것
                dist[pos] = dist[tmp];
            q.push(pos);
        }
    }
    cout<<dist[100];
}