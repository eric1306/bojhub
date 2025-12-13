// Authored by: prid1306
#include <iostream>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int t,n,k,w;
int d[1001];
vector<int> adj[1001];
int dp[1001];
bool visited[1001];
/*
1. 출발지가 무조건 1번이 아님.
- 따라서 w에서 역추적 하는 방식으로 구해야함.
d[4] : max(d[1], d[2], d[3] + 4 199'999 + 99'997 + 99'994
d[3] : max(d[1], d[2]) + 3 199'999 + 99'997
d[2] = d[1] + 2 : 199'999
d[1] : 100'000
*/
int dfs(int pos)
{
    if(dp[pos] != -1) return dp[pos];
    dp[pos] = 0;
    for(auto elem : adj[pos])
    {
        //adj개 중에서 가장 max인 값을 더해야함.
        dp[pos] = max(dp[pos], dfs(elem));
    }
    return dp[pos] = dp[pos] + d[pos];
}
int main(){
    FASTIO;
    cin>>t;
    while(t--)
    {
        fill(dp, dp + 1001, -1);
        for(int i=0;i<1001;i++)
        {
            adj[i].clear();
        }
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>d[i];
        }
        for(int i=0;i<k;i++)
        {
            int from,to;
            cin>>from>>to;
            adj[to-1].emplace_back(from-1);
        }
        cin>>w;
        cout<<dfs(w - 1)<<'\n';
    }

}