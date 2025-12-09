// Authored by: prid1306
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
/*
기존 LCS와는 다르게 출력을 해야함.
d[i][j]: A의 i번째, B의 j번째 LCS
if(a[i] == b[i]) d[i][[j] = d[i-1][j-1] + 1;
else if(a[i]!=b[i]) d[i] = max(d[i-1][j], d[i][j-1]);
초기값: d[0][x] = d[x][0] = 0; , d[0][0] = 0;

문제점: 벡터 복사 때문에 시간 초과 발생. move? 나중에 참조할 수도 있으니 안됨.
그리고 커스텀 선언하지 않은 move는 복사 생성과 다를바가 없음.

일단 기존 방식인 벡터로 복사는 절대 안됨 그렇다면
현재의 값과, 이전에 참조한 값을 보관하는 식으로 구현?
일단 역추적을 할 수 있는 컨테이너가 무조건 필요함 -> 뭘로 할 거임? (고민좀 해야할듯)
a[i] == b[j] 라면? a[i] != b[j]라면?
bool 변수와 int값 두개를 두고
이 숫자가

*/
int d[1001][1001];
bool issame[1001][1001];
pair<int,int> p[1001][1001];
string a,b;
vector<char> ans;
int main(){
    FASTIO;
    cin>>a>>b;
    //초기값 설정
    for(int i=0;i<a.size();i++)  d[i][0] = 0;
    for(int i=0;i<b.size();i++)  d[0][i] = 0;
    //DP
    for(int i=1;i<=a.size();++i)
    {
        for(int j=1;j<=b.size();++j)
        {
            if(a[i-1] == b[j-1])
            {
                d[i][j] = d[i-1][j-1] + 1;
                issame[i][j] = true;
                p[i][j] = {i-1, j-1};
            }
            else
            {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
                issame[i][j] = false;
                if(d[i-1][j] > d[i][j-1])
                {
                    p[i][j] = {i-1, j};
                }
                else
                {
                    
                    p[i][j] = {i, j - 1};
                }
            }
        }
    }
    cout<<d[a.size()][b.size()]<<'\n';
    int x = a.size(), y = b.size();
    while(x != 0 || y != 0)
    {
        if(issame[x][y]) ans.emplace_back(a[x-1]);
        auto cur = p[x][y];
        x = cur.first;
        y = cur.second;
    }
    reverse(ans.begin(), ans.end());
    for(auto elem : ans) cout<<elem;
}