// Authored by: prid1306
// BOJ 9251
#include <iostream>
#include <string>
using namespace std;
int d[1001][1001];
string s1,s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s1>>s2;
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1] == s2[j-1]) d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = max(d[i-1][j],d[i][j-1]);
        }
    }
    cout<<d[s1.size()][s2.size()];
}