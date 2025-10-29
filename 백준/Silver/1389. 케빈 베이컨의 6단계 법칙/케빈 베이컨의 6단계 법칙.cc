// Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,m;

int main(){
    FASTIO;
    cin>>n>>m;
    vector<int> adj[101];
    for(int i=0;i<m;i++) //인접 리스트로 관리
    {
        int l,r;cin>>l>>r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    int ans = 0x7fffffff; //가장 작은 케빈 베이컨 수를 담는 변수
    int ansUser = 0; //가장 작은 케빈 베이컨 수를 가지는 유저 캐싱
    for(int i=1;i<=n;i++)
    {
        vector<int> len(n+1, 0); //i와의 거리를 표현하기 위한 벡터 배열
        queue<int> q;
        q.push(i);
        len[i] = 0;
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            for(int nxt : adj[p])
            {
                if(len[nxt]) continue; //이미 차있다면 스킵
                len[nxt] = len[p] + 1;
                q.push(nxt);
            }
        }
        int tmp = 0;
        for(int i=1;i<=n;i++)
        {
            tmp+=len[i];
        }
        if(ans > tmp)
        {
            ans = tmp;
            ansUser = i;
        }
    }
    cout<<ansUser;
}