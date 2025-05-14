//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define x first
#define y second

int n,m;
int a[1001][1001];

int findlen(int from, int to)
{
    vector<bool> visit(1001, false);
    queue<pair<int,int>> q;
    q.emplace(from,0);
    visit[from] = true;
    while(!q.empty())
    {
        pair<int,int> p = q.front();q.pop();
        for(int i=1;i<=n;i++)
        {
            //연결짓는 가중치가 없거나 방문했었다면
            if(p.x == i || a[p.x][i] == 0 || visit[i]) continue;
            if(i == to){
                //얘와의 거리를 반환하면 됨.
                return a[p.x][i] + p.y;
            }
            //그게 아니면 queue에 넣기
            q.emplace(i,p.y + a[p.x][i]);
            visit[i] = true;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int from,to,len;
    for(int i=0;i<n-1;i++)
    {
        cin>>from>>to>>len;
        a[from][to] = len;
        a[to][from] = len;
    }
    while(m--)
    {
        cin>>from>>to;
        cout<<findlen(from,to)<<'\n';
    }
}