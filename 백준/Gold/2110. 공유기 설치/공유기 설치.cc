//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;

//i_1,i_2...i_c를 선택할 때 각 점 간의 거리 중 하나 가 최소값이어야 함.
// 예정대로라면 O(N^C) -> 100% 시간초과
//특정 부분에 이분탐색을 적용해야함.
//최대 거리: x로 두고 mid값으로 정한 다음에 거리에 건물 있는지 탐색.

int n,c,ans;
int a[200'002];

bool solve(int x)
{
    int cnt = 1;
    int last_pos = a[0];
    for(int i=1;i<n;i++)
    {  
        if(a[i] - last_pos >= x)
        {
            cnt ++;
            last_pos = a[i];
        }
    }

    return cnt >= c;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>c;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a, a+n);
    int st = 1;
    int en = *max_element(a,a+n);
    while(st <= en)
    {
        int mid = (st + en)/2;
        if(solve(mid))
        {
            ans = mid;
            st = mid+1;
        }
        else en = mid-1;
    }
    cout<<ans;
}