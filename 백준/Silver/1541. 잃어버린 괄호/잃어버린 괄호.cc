//Authored by: prid1306
#include <iostream>
using namespace std;
string n;
/*
-가 나오는 순간 가로 열고, +이면 가로 진행, -이면 가로 닫기
*/
int ans, num;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int signal = 1;
    for(int i=0;i<n.size();i++)
    {
        if(n[i]!='+' && n[i]!='-')
        {
            num = num*10 + (int)(n[i] - '0');
        }
        else
        {
            ans += num * signal;
            if(n[i] == '-'){
                signal = -1;
            }
            num = 0;
        }
    }
    //마지막 처리
    ans += num * signal;
    cout<<ans;
}