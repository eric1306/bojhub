// Authored by: prid1306
#include <iostream>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
string s[101];
const string DORO = "DORO";
int main(){
    FASTIO;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<DORO<<' ';
    }
}