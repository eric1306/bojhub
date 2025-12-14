// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main(){
    FASTIO;
    int n,input,ans = 0;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>input;
        ans+= input%2 == 0 ? input/2 : input/2 + 1;
    }
    cout<<ans;
}