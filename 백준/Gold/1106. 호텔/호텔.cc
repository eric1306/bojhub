// Authored by: prid1306
#include <iostream>
#include <queue>
#include <tuple>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
vector<pair<int,int>> v; //최소공배수로 약분된 비용, 고객수가 저장된 배열
int c,n;
tuple<int,int, int> lastInfo;
int d[1101]; //d[i]: 호텔의 고객 i명 늘리기 위해 형택이가 투자해야 하는 돈의 최솟값.
//점화식 d[i] = min(d[i - cost] + number, d[i])
//초기값: d[0] = 0;
int main(){
    FASTIO;
    cin>>c>>n;
    for(int i=0;i<n;i++)
    {
        int cost, customerNum;
        cin>>cost>>customerNum;
        v.emplace_back(cost, customerNum);
    }
    fill(d, d + 1101, 1e9);
    d[0] = 0;
    for(auto elem : v) //가장 최소값으로 갱신됨. 근데 이건 1번만 사용한 경우
    {
        for(int i=1;i*elem.second <= c + 100; i++)
        {
            d[i*elem.second] = min(d[i*elem.second], i*elem.first);
        }
    }
    //여러개가 겹쳐지는 경우를 고려
    for(auto elem : v)
    {
        for(int i=1;i <= (c + 100); i++)
        {
            if(i - elem.second >= 0)
            {
                d[i] = min(d[i - elem.second] + elem.first, d[i]);
            }
        }
    }

    int ans = 0x7fffffff;
    for(int i=c;i<=(c + 100); i++)
    {
        ans = min(ans, d[i]);
    }

    cout<<ans;
}