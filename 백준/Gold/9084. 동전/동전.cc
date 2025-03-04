//Authored by: prid1306
#include <iostream>
using namespace std;
int t,n,m;
int coin[21];
int d[10001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        //배열 초기화
        fill(coin,coin+21,0);
        fill(d,d+10001,0);

        cin>>n;
        for(int i=0;i<n;i++){
            cin>>coin[i];
        }
        d[0] = 1;
        cin>>m;
        /*
        coin[0]+1 ~ M원까지 dp 돌려야함.
        */
        for(int i=0;i<n;i++)
        {
            for(int j=coin[i];j<=m;j++)
            {
                d[j] +=d[j-coin[i]];
                //i번째 코인을 사용해서 j를 만들 수 있는 경우는 d[j-coin[i]]
                //d[0] = 1설정하지 않으면 d[coin[i]] 값이 설정 안됨.
            }
            //cout<<"d["<<i<<"]: "<<d[i]<<'\n';
        }
        cout<<d[m]<<'\n';
    }
}