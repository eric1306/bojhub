#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<bool> state;

void seive(int m,int n)
{
    vector<int> primes;

    state[1] = false;

    for(int i=2;i*i<=n;i++)
    {
        if(!state[i]) 
            continue;

        for(int j = i*i;j<=n;j+=i)
        {
            state[j] = false;
        }
    }

    for(int i=m;i<=n;i++)
    {
        if(state[i])
            cout<<i<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    state.resize(1'000'001, true);
    seive(m,n);
}