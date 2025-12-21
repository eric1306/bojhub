// Authored by: prid1306
#include <iostream>
#include <vector>
#include <tuple>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
vector<int> op;
int l,r;
int cost[4] = {1, 3, 4, 3};
int dp[100'001][5][5];
/*
dp[i][j][k]: i번째 명령까지 마쳤고, 플레이어가 (j, k)에 위치할 때의 value
dp[i][j[k]
*/

int main(){
    FASTIO;
    int input;
    cin>>input;
    for(int i=0;i<100'001;i++) for(int j=0;j<5;j++)
    {
        fill(dp[i][j], dp[i][j] + 5, 1e9);
    }
    while(input!=0)
    {
        op.emplace_back(input);
        cin>>input;
    }
    dp[0][0][0] = 0;
    for(int i=1;i<=op.size();i++)
    {
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(dp[i-1][j][k] != 1e9)
                {
                    //cout<<"i: "<<i-1<<" j: "<<j<<" k: "<<k<<" op: "<<op[i-1]<<'\n';
                    dp[i][op[i-1]][k] = min(dp[i][op[i-1]][k], dp[i-1][j][k] + (j == 0 ? 2 : cost[abs(j - op[i-1])%4]));
                    dp[i][j][op[i-1]] = min(dp[i][j][op[i-1]], dp[i-1][j][k] + (k == 0 ? 2 : cost[abs(k - op[i-1])%4]));
                    //cout<<"dp["<<i<<"]["<<op[i-1]<<"]["<<k<<"]: "<<dp[i][op[i-1]][k]<<'\n';
                    //cout<<"dp["<<i<<"]["<<j<<"]["<<op[i-1]<<"]: "<<dp[i][j][op[i-1]]<<'\n';
                }
            }
        }
    }
    int ans = 1e9;
    int size = op.size();
    for(int i=0;i<5;i++) for(int j=0;j<5;j++)
    {
        //cout<<dp[size][i][j]<<'\n';
        ans = min(ans, dp[size][i][j]);
    }
    cout<<ans;
}
