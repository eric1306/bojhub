//Authored by: prid1306
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n,m;
unordered_map<string, string> map;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    string site,pw;
    while(n--)
    {
        cin>>site>>pw;
        map[site] = pw;
    }
    string findurl;
    while(m--)
    {
        cin>>findurl;
        cout<<map[findurl]<<'\n';
    }
}