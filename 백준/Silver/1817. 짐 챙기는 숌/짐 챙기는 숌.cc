// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,m;
int main(){
    FASTIO;
    cin>>n>>m;
    int bucket = 0;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int input;cin>>input;
        if(bucket + input > m)
        {
            bucket = 0; ans++;
            bucket += input;
        }
        else
        {
            bucket += input;
        }
    }
    if(bucket != 0) ans++;
    cout<<ans;
}