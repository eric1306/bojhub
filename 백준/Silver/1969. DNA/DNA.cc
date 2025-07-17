// Authored by: prid1306
// BOJ 1969
#include <iostream>
#include <string>
using namespace std;
int arr[51][4];
int n,m;
string cmp = "ACGT";
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(n--){
        string s;cin>>s;
        for(int i=0;i<m;i++){
            int idx = cmp.find(s[i]);
            arr[i][idx]++;
        }
    }
    int sum = 0;
    for(int i=0;i<m;i++){
        int mx = -1,idx = -1;
        for(int j=0;j<4;j++){
            sum+=arr[i][j];
            if(mx >= arr[i][j]) continue;
            mx = arr[i][j];
            idx = j;
        }
        sum -= mx;
        cout<<cmp[idx];
    }
    cout<<'\n'<<sum;
} 