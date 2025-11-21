// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,m;
vector<int> a;
vector<int> b;
bool IsInB(int st, int value)
{
    for(int i=st; i<m;i++)
    {
        if(b[i] == value)
            return true;
    }
    return false;
}
int main(){
    FASTIO;
    cin>>n; a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>m;b.resize(m);
    for(int i=0;i<m;i++) cin>>b[i];
    vector<int> ret;
    int posA=0, posB=0;
    while(posA < n && posB < m)
    {
        int maxValue = -1;
        for(int i=posA; i< n;i++)
        {
            if(IsInB(posB, a[i])){
                maxValue = max(maxValue, a[i]);
            }
        }
        if(maxValue == -1) break;
        ret.push_back(maxValue);
        for(int i = posA;i<n;i++){
            if(a[i] == maxValue)
            {
                posA = i + 1; break;
            }
        }
        for(int i = posB;i<m;i++){
            if(b[i] == maxValue)
            {
                posB = i + 1;break;
            }
        }
    }
    cout<<ret.size()<<'\n';
    for(int elem : ret) cout<<elem<<' ';
    //최대 부분 수열을 찾기
    //그럼 공통 부분 수열들은 최대 공통 부분 수열의 부분 수열일 수 밖에 없음
    // -> 왜냐하면
    // 최대 공통 부분 수열 reverse 에서 LCS 찾기?
}