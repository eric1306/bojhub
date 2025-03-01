//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int t[16];
int p[16];
// i 번째 날까지 상담했을때 백준이 얻는 최대 이익
//단 i번째 날의 상담은 반드시 했음
int d[16];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i]>>p[i];
    if(1 + t[1] <= n+1) d[1] = p[1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(i + t[i] > n+1) continue;
            if(t[j] <= i-j)
            {
                d[i] = max(d[i],d[j] + p[i]);
            }
            else
            {
                if(i + t[i] <=n+1)
                    d[i] = max(d[i],p[i]);
            }
        }
    }
    cout<<*max_element(d+1,d+n+1);
}