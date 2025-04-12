//Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
const int MAX = 4'000'001;
vector<bool> state;
vector<int> prime;
void GetPrime()
{
    state.resize(n+1, true);
    state[1] = false;
    for(int i=2;i*i<=n;i++)
    {
        if(!state[i]) continue;
        for(int j = i*i;j<=n;j+=i)
        {
            if(state[j]) state[j] = false;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(state[i]) prime.push_back(i);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    //get primes.
    GetPrime();
    int vsize = prime.size();
    int en = 0;
    int sum = prime.size() ? prime[0] : 0;
    int ans = 0;
    for(int st = 0;st<vsize;st++)
    {
        while(en < vsize && sum < n){
            en++;
            if(en!=vsize) sum+=prime[en];
        }
        if(en == vsize) break;
        if(sum == n){
            ans++;
        }
        sum -= prime[st];
    }
    cout<<ans;
}