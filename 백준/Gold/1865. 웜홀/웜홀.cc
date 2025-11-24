// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
//시간이 줄어들면서 처음 위치로 돌아오는게 가능하게
// == 시작지점 -> 도착지점까지 도로로 갈 때 걸리는 시간 < 도착지점 -> 시작지점까지 웜홀로 갔을 때 감소되는 시간
//floyd-warshall 써야지
int tc;
const int INF = 1e9;
int main(){
    FASTIO;
    cin>>tc;
    while(tc--) // <= 5
    {
        int a[501][501];
        for(int i=0;i<501;i++){
            fill(a[i], a[i] + 501, INF);
        }
        int n,m,w,s,e,t;
        cin>>n>>m>>w; // <= 500, <= 2500, <= 200
        for(int i=0;i<m;i++)
        {
            cin>>s>>e>>t;
            
            if(t < a[s-1][e-1]) a[s-1][e-1] = a[e-1][s-1] = t;
        }
        for(int i=0;i<w;i++)
        {
            cin>>s>>e>>t;
            if(-t < a[s-1][e-1]) a[s-1][e-1] = -t;
        }
        for(int via = 0; via < n; via++)
        {
            for(int from = 0; from < n; from++)
            {
                for(int to = 0; to < n; to++)
                {
                    if(a[from][to] > a[from][via] + a[via][to])
                        a[from][to] = a[from][via] + a[via][to];
                }
            }
        }
        bool bflag = true;
        for(int i=0;i<n;i++){
            if(a[i][i] < 0){
                bflag = false; break;
            }
        }
        if(bflag) cout<<"NO\n";
        else cout<<"YES\n";
    }
}