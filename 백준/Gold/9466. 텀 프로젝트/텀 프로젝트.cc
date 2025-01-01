#include <iostream>
using namespace std;

int arr[100005];
int status[100005];
int n;
const int NOT_VISIT = 0;
const int CYCLE_IN = -1;
void run(int x)
{
    int cur = x;
    while(true){
        status[cur] = x;
        cur = arr[cur];
        if(status[cur] == x)// 이번 run에 발생한 CYCLE.
        {
            while(status[cur] == x){
                status[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
        //이전방문 도달
        else if(status[cur] != 0) return;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        fill(status+1,status+n+1, 0);
        for(int i=1;i<=n;i++) cin>>arr[i];
        for(int i=1;i<=n;i++) if(status[i] == NOT_VISIT) run(i);
        int ans = 0;
        for(int i=1;i<=n;i++) if(status[i] != CYCLE_IN) ans++;
        cout<<ans<<'\n';
    }
}