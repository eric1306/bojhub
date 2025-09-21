// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n;
int ans = 0;
/*
가로, 세로, 대각선을 고려해야한다
가로 -> k행 마다 한개씩 배치하고 넘어가기 때문에 고려X
세로 -> isused로 해당 열이 사용되었는지 체크하는 bool 배열 만들면 된다
대각선 -> 대각선도 결국 배열로 표기 가능함
 - 오른쪽 방향 대각선은 간단함(행 + 열 대각선 표기 가능.)

*/
bool isusedcol[15];
bool isusedright[30];
bool isusedleft[30];
void BT(int k)
{
    if(k == n){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(isusedcol[i] || isusedright[i + k] || isusedleft[i + n - k])
            continue;
        isusedcol[i] = true;
        isusedright[i + k] = true;
        isusedleft[i + n - k] = true;
        BT(k+1);
        isusedcol[i] = false;
        isusedright[i + k] = false;
        isusedleft[i + n - k] = false;
    }
}
int main(){
    FASTIO;
    cin>>n;
    BT(0);
    cout<<ans;
}