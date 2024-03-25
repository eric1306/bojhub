#include <iostream>
using namespace std;

// 0과 1이 각각 몇 번 출력되는지 구하는 문제
int dp[41][2];
void filldp(){
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i=2;i<=40;i++){
        dp[i][0] = dp[i-1][0]+dp[i-2][0];
        dp[i][1] = dp[i-1][1]+dp[i-2][1];
    }
    
}
int main(){
    filldp();

    int tc,n;
    cin>>tc;
    while(tc--){
        cin>>n;
        cout<<dp[n][0]<<' '<<dp[n][1]<<'\n';
    }
    return 0;
}
