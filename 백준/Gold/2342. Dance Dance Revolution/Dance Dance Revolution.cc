// Authored by: prid1306
#include <iostream>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int l,r;
int cost[4] = {1, 3, 4, 3};
int DP[5][5];
int newDP[5][5];
/*
dp[i][j][k]: i번째 명령까지 마쳤고, 플레이어가 (j, k)에 위치할 때의 value
dp[i][j[k]
*/

int main(){
    FASTIO;
    for(int j=0;j<5;j++)
    {
        fill(DP[j], DP[j] + 5, 1e9);
    }
    DP[0][0] = 0;
    while(true)
    {
        int input;cin>>input;
        if(input == 0) break;
        for(int i=0;i<5;i++) fill(newDP[i], newDP[i] + 5, 1e9);
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(DP[j][k] == 1e9) continue;
                newDP[input][k] = min(newDP[input][k], DP[j][k] + (j == 0 ? 2 : cost[abs(j - input)%4]));
                newDP[j][input] = min(newDP[j][input], DP[j][k] + (k == 0 ? 2 : cost[abs(k - input)%4]));
            }
        }
        swap(DP, newDP);
    }
    int ans = *min_element(&DP[0][0], &DP[0][0] + 25);
    cout<<ans;
}
