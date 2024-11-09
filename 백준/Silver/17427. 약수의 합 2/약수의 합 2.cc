#include <iostream>
using namespace std;


int main()
{
    int n;
    long long ans = -1;

    cin>>n;
    
    for(int j = 1; j <= n;j++)
    {
        ans+=j+1;
    }

    for(int i=2;i*i<=n;i++)
    {
        for(int j=i+1;i*j<=n;j++)
        {
            ans += i+j;
        }
    }
    
    for(int i=2;i*i<=n;i++)
    {
        ans += i;
    }
    cout<<ans;
}