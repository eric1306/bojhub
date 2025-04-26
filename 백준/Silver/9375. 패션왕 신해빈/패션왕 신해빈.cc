//Authored by: prid1306
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n;
//해빈아 ㅅㅂ 다해줬잖아
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        unordered_map<string, int> m;
        string cloth, clothtype;
        for(int i=0;i<n;i++){
            cin>>cloth>>clothtype;
            m[clothtype]++;
        }
        int ans = 1;
        for(auto c : m) 
            ans*=c.second+1;

        cout<<ans-1<<'\n';
    }
}