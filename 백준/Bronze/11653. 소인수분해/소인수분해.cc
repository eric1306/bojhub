#include <iostream>
using namespace std;

int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int idx = 2;
    while(n >= idx * idx)
    {
        while(n%idx == 0)
        {
            cout<<idx<<'\n';
            n = n/idx;
        }
        idx++;
    }
    if(n!=1) cout<<n;
}