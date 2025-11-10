// Authored by: prid1306
#include <iostream>
#include <queue>
#include <utility>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using pii = pair<int,int>;
using piipii = pair<pii,pii>;
#define x first
#define y second
int n;
int board[16][16];
int ans = 0;

bool OOB(int x, int y)
{
    return (x < 0 || x >= n || y < 0 || y >= n);
}

bool isWall(int x1, int y1, int x2, int y2)
{
    if(x2 - x1 == 1 && y2 - y1 == 1)
    {
        if(board[x2][y2] == 1 || board[x2-1][y2] == 1 || board[x2][y2-1] == 1) 
            return true;
    }
    else
    {
        if(board[x2][y2] == 1) 
            return true;
    }
    return false;
}

void BFS(const pii& nxt, const pii& front, const pii& back, queue<piipii>& q)
{
    int nfrontX = front.x;
    int nfrontY = front.y;
    int nbackX = back.x + nxt.x;
    int nbackY = back.y + nxt.y;
    if(OOB(nbackX, nbackY)) return; //Out of range
    if(isWall(nfrontX, nfrontY, nbackX, nbackY)) return; //벽과 걸림
    if(nbackX == n-1 && nbackY == n- 1){ ans++; return;}
    q.push(make_pair(make_pair(nfrontX, nfrontY), make_pair(nbackX, nbackY)));
    //cout<<"Push!"<<nfrontX<<","<<nfrontY<<"->"<<nbackX<<","<<nbackY<<'\n';
}

int main(){
    FASTIO;
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        cin>>board[i][j];
    }
    //현재 시작점을 st로 잡고, 파이프가 어떻게 있냐에 따라 이동방법 제한됨
    piipii st = {{0,0},{0,1}};
    queue<piipii> q;
    q.push(st);
    while(!q.empty())
    {
        auto p = q.front();q.pop();
        pii front = p.x;
        pii back = p.y;
        if(back.x - front.x == 1 && back.y - front.y == 1)
        {
            //대각선
            for(pair<int,int> nxt : {make_pair(-1, 0), make_pair(0, -1), make_pair(0,0)})
            {
                BFS(nxt, make_pair(front.x + 1, front.y + 1), make_pair(back.x + 1, back.y + 1), q);
            }
        }
        else if(back.x == front.x)
        {
            //가로
            for(pair<int,int> nxt : {make_pair(1, 0), make_pair(0, 0)})
            {
                BFS(nxt, make_pair(front.x, front.y + 1), make_pair(back.x, back.y + 1), q);
            }
        }
        else if(back.y == front.y)
        {
            //세로
            for(pair<int,int> nxt : {make_pair(0, 1), make_pair(0, 0)})
            {
                BFS(nxt, make_pair(front.x + 1, front.y), make_pair(back.x + 1, back.y), q);
            }
        }
    }
    
    cout<<ans;
}