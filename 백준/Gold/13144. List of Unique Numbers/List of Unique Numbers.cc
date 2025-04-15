//Authored by: prid1306
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> a(n);
    vector<bool> chk(100'002);
    for(int i=0;i<n;i++) cin>>a[i];
    long long ans = 0;
    chk[a[0]] = 1;
    int en = 0;
    for(int st=0;st<n;st++)
    {
        while(en < n-1 && !chk[a[en + 1]])
        {
            en++;
            chk[a[en]] = 1;
        }
        ans+=(en-st + 1);
        chk[a[st]] = 0;
    }
    cout<<ans;
}