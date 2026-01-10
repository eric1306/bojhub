// Authored by: prid1306
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
#define x first
#define y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0 ,1, 0, -1};
int n,m;
string input[1001];
int board[1001][1001];
int group[1001][1001];

inline bool OOB(int i, int j)
{
    return (i < 0 || i >= n || j < 0 || j >= m);
}

int main(){
    FASTIO;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
        for(int j=0;j<m;j++)
        {
            board[i][j] = input[i][j] - '0';
        }
    }
    //bfs 순회하면서 모든 0들을 그룹화 하기.
    int groupNum = 2;
    vector<int> groupVec;
    groupVec.push_back(-1);
    groupVec.push_back(-1);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        if(board[i][j] == 1 || group[i][j] != 0) continue;
        int num = 1;
        queue<pair<int,int>> q;
        q.emplace(i, j);
        group[i][j] = groupNum;
        while(!q.empty())
        {
            auto p = q.front();q.pop();
            for(int idx = 0; idx < 4; idx++)
            {
                int nx = p.x + dx[idx];
                int ny = p.y + dy[idx];
                if(OOB(nx, ny)) continue;
                if(board[nx][ny] == 1) continue;
                if(group[nx][ny]) continue;
                q.emplace(nx, ny);
                group[nx][ny] = groupNum;
                num++;
            }
        }
        groupVec.push_back(num);
        groupNum++;
    }

    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        if(board[i][j] != 1) continue;
        vector<bool> bIsGroupUsed(groupVec.size(), false);
        for(int k=0;k<4;k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(OOB(nx, ny)) continue;
            if(board[nx][ny] != 0) continue;
            if(bIsGroupUsed[group[nx][ny]]) continue;
            board[i][j] += groupVec[group[nx][ny]];
            bIsGroupUsed[group[nx][ny]] = true;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<board[i][j]%10;
        }
        cout<<'\n';
    }
}