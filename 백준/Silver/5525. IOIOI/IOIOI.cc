// Authored by: prid1306
#include <iostream>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,m;
string s;
int main(){
    FASTIO;
    cin>>n>>m>>s;
    int ans = 0;
    for(int i=0;i<m;i++)
    {
        int k = 0;
        if(s[i] == 'O') continue;
        while(s[i+1] == 'O' && s[i+2] == 'I')
        {
            k++;
            if(k == n){
                ans++;
                k--;
            }
            i+=2;
        }
    }
    cout<<ans;
}