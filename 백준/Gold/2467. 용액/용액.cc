#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int n;
int a[100001];
ll ans = 2'000'000'000;
ll ans_st,ans_en;
//n^2는 10억으로 시간초과 발생. 이분
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int st = 0;
    int en = n-1;
    while(st < en)
    {
        ll tmp = a[st] + a[en];
        if(ans > abs(tmp)){
            ans = abs(tmp);
            ans_st = st;
            ans_en = en;
        }
        else //ans <= abs(tmp)
        {
            //st++을 해줄지, en--를 해줄지 결정해야함.
            ll tmp1 = a[st+1] + a[en];
            ll tmp2 = a[st] +  a[en-1];
            if(abs(tmp1) < abs(tmp2))
                st++;
            else
                en--;
        }
    }
    cout<<a[ans_st] <<' '<< a[ans_en]<<'\n';
}