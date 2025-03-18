#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,ans = 0,min=0;
    cin>>m>>n;
    for(int i=1;i*i<=n;i++)
    {
        if(i*i >=m)
        {
            ans+=i*i;
            if(min == 0) min = i*i;
        }
    }
    if(ans == 0) cout<<-1<<'\n';
    else{
        cout<<ans<<'\n';
        cout<<min;
    }
    
}