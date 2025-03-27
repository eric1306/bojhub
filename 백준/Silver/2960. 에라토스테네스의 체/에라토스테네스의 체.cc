#include <iostream>
#include <vector>
using namespace std;
int n,k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    cin>>n>>k;
    vector<int> prime;
    vector<bool> state(1001, true);
    state[1] = false;
    for(int i=2;i<=n;i++)
    {
        if(!state[i]) continue;
        state[i] = false;
        cnt++;
        //cout<<i<<' '<<cnt<<'\n';
        if(cnt == k){
            cout<<i;
            return 0;
        }
        for(int j=i*i;j<=n;j+=i)
        {
            if(!state[j]) continue;
            state[j] = false;
            cnt++;
            //cout<<j<<' '<<i<<' '<<cnt<<'\n';
            if(cnt == k){
                cout<<j;
                return 0;
            }
        }
    }
}