// Authored by: prid1306
#include <iostream>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using pii = pair<int,int>;
int ans;
int main(){
    FASTIO;
    int t,n,m;cin>>t;
    while(t--)
    {
        cin>>n>>m;
        //그냥 n과 m에서 같은게 몇개인지 체크
        //100 * 100 * 100. 이라 최대 1'000'000
        vector<int> bu(n);
        vector<int> lr(m);
        for(int i=0;i<n;i++) cin>>bu[i];
        for(int i=0;i<m;i++) cin>>lr[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(bu[i] == lr[j]) ans++;
            }
        }
        cout<<ans<<'\n';
        ans = 0;
    }
}