// Authored by: prid1306
// BOJ 2999
#include <iostream>
#include <string>
using namespace std;
int n;
char a[101][101];
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    n = s.length();
    int mx = 1;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0) mx = i;
    }
    int r=mx,c=n/mx;
    for(int i=0;i<c;i++) for(int j=0;j<r;j++){
        a[j][i] = s[i*r + j];
    }
    for(int i=0;i<r;i++) for(int j=0;j<c;j++){
        cout<<a[i][j];
    }
} 