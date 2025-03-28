//Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
const int MaxVal = 123457*2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    vector<bool> state(MaxVal, true);
    state[1] = false;
    for(int i=2;i*i<=MaxVal;i++)
    {
        if(!state[i]) continue;
        for(int j=i*i;j<MaxVal;j+=i)
        {
            if(state[j])
                state[j] = false;
        }
    }
    while(n!=0)
    {
        int count = 0;
        for(int i=n+1;i<=n*2;i++)
        {
            if(state[i]) count++;
        }
        cout<<count<<'\n';
        cin>>n;
    }
}