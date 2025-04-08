//Authored by: prid1306
#include <iostream>
using namespace std;
using ull = unsigned long long;
ull n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    ull cnt = 1,sum = 0,compnum = 10,jari = 1;
    for(int i=0;i<n;i++)
    {
        if(jari + sum >= k)
        {
            //cout<<jari<<' '<<sum<<' '<<k<<' '<<'\n';
            for(int j=1;j<=jari;j++)
            {
                if(j + sum == k){
                    int ans = 0;
                    int cntans = jari - j + 1;
                    //cout<<"cntans : "<<cntans<<'\n';
                    while(cntans--)
                    {
                        ans = cnt%10;
                        cnt/=10;
                    }
                    cout<<ans;
                    return 0;
                }
            }
        }
        sum+=jari;
        cnt++;
        // cout<<jari<<' '<<sum<<' '<<cnt<<'\n';

        if(cnt == compnum)
        {
            compnum*=10; jari++;
        }
    }
    cout<<-1;
}