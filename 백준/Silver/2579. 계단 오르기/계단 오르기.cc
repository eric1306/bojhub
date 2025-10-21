// Authored by: prid1306
#include <iostream>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int d[301][3]; //d[i][j]: i번째 계단인데, 이전에 j개의 계단을 밟은 경우
//예를 들어서 d[279][2]: 279번계단인데, 이전에 278번 계단을 밟은 경우
int stairs[301];
/*
점화식
내가 i번째 칸으로 오는 경우는
1) 연속해서 3개 미만의 계단을 밟은 경우(즉, i-1번째 계단에서 오는 경우)
2) i-2번째 칸에서 점프하는 경우
*/
int main(){
    FASTIO;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stairs[i];
    }
    if(n == 1){
        cout<<stairs[1]<<'\n';
        return 0;
    }else if(n ==2){
        cout<<stairs[1] + stairs[2]<<'\n';
        return 0;
    }

    d[1][1] = stairs[1]; 
    d[2][1] = stairs[2];d[2][2] = d[1][1] + stairs[2];
    for(int i=3;i<=n;i++){
        d[i][1] = max(d[i-2][1], d[i-2][2]) + stairs[i];
        d[i][2] = d[i-1][1] + stairs[i];
    }
    int ans = -1;
    for(int i=0;i<3;i++){
        if(ans < d[n][i]) ans = d[n][i];
    }
    cout<<ans<<'\n';
}