#include <bits/stdc++.h>
using namespace std;
int student[2][7];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,s,y,ans = 0;
    cin>>n>>k;
    /*put student*/
    for(int i=0;i<n;i++){
        cin>>s>>y;
        student[s][y]++;
    }
    for(int i=1;i<7;i++){
        if(student[0][i])
            ans+=(student[0][i]/k)+(student[0][i]%k ? 1 : 0 );
        if(student[1][i])
            ans+=(student[1][i]/k)+(student[1][i]%k ? 1 : 0 );
    }
    cout<<ans;
}