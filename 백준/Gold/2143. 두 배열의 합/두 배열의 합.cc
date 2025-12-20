// Authored by: prid1306
#include <iostream>
#include <unordered_map>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int t,n,m;
unsigned long long ans;
int a[1001][1001];
int b[1001][1001];
unordered_map<int,int> dt;

int main(){
    FASTIO;
    cin>>t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i][i];
        if(i == 0) continue;
        for(int j=0;j<i;j++)
        {
            a[j][i] = a[j][i-1] + a[i][i];
        }
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>b[i][i];
        dt[b[i][i]]++;
        if(i == 0) continue;
        for(int j=0;j<i;j++)
        {
            b[j][i] = b[j][i-1] + b[i][i];
            dt[b[j][i]]++;
        }
    }
    /*
    a[1] / b[1] ~ b[m]
    a[1] + a[2] / b[1] ~ b[m]
    a[1] + ...a[n] /
    n번 + n-1 ..... 번 : m^2*n^2;1'000'000'000 
    어디선가 log때려야함.
    1) 합이 T가 된다면 더이상 탐색하지 않고 종료
    2) 한 개 배열의 부 배열의 합이 T라면 이후는 볼 필요 없음.
    - 근데 만약 1 3 1 5 -4 | -1 이라면 얘도 부배열의 합으로 이루어짐. 따라서 2번은 오류
    3) 
    만약 내가 모든 부 배열의 합을 사전에 알 수 있다면?
    부 배열의 개수는 각각 n^2, m^2개.
    그래도 시간 초과가 날 것이다.
    DP? 문제를 쪼갤 수가 없다.
    */
    for(int i=0;i<n;i++){
        int asum = 0;
        for(int j=i;j<n;j++)
        {
            asum+=a[j][j];
            //cout<<"a i..j: "<<asum<<'\n';
            auto it = dt.find(t - asum);
            if(it != dt.end())
            {
                //cout<<"find!\n";
                ans+=(*it).second;
            }
        }
    }
    cout<<ans;
}