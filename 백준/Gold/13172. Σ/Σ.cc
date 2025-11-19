// Authored by: prid1306
#include <iostream>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using ull = unsigned long long;
int m;
vector<pair<int,int>> v;
ull ans = 0;
const int X = 1'000'000'007;
int main(){
    FASTIO;
    cin>>m;
    //지금은 수가 하나여서 OK 지만, 만약 수가 여러개라면?
    for(int i=0;i<m;i++){ //O(m)
        ull b,a;cin>>b>>a;
        if(a%b == 0){
            ans += a/b; 
            continue;
        }
        //b^(X-2) 구하기
        int value = X - 2;
        ull tmp = 1;
        ull tmp2 = b;
        while(value)
        {
            if(value % 2 == 1)
            {
                tmp = tmp * tmp2;
                tmp %= X;
            }
            value /= 2;
            tmp2 = tmp2 * tmp2;
            tmp2 %= X;
        }
        ans = (ans % X + a * tmp % X) % X;
    }
    cout<<ans;
}