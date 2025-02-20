//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int arrn[20001];
int arrm[20001];
int n,m,t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        int ans = 0;
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>arrn[i];
        for(int i=0;i<m;i++) cin>>arrm[i];
        sort(arrn,arrn+n,greater<>());
        sort(arrm,arrm+m,greater<>());
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arrn[i] > arrm[j]){
                    ans+=m-j;
                    break;
                }
            }
        }
        cout<<ans<<'\n';
    }
}