//Authored by: prid1306
#include <iostream>
using namespace std;
int n,d,k,c;
int a[30002];
int sushi[3002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>d>>k>>c;
    for(int i=0;i<n;i++) cin>>a[i];
    int en = 0,ans = 1;
    sushi[a[0]]++;
    for(int st = 0;st < n;st++){
        while(en - st + 1 < k){
            en++;
            sushi[a[en%n]]++;
        }
        int sushikind = 0;
        for(int i=0;i<=3000;i++){
            if(sushi[i]) sushikind++;
        }
        if(!sushi[c]) sushikind++;
        ans = max(ans, sushikind);
        sushi[a[st]]--;
    }
    cout<<ans;
}