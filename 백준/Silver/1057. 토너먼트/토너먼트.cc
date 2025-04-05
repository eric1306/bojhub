//Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,jm,hs;

int nextnum(int num)
{
    return num%2 == 0 ? num/2 : (num+1)/2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>jm>>hs;
    if(jm > hs) swap(jm, hs);
    int cnt = 1;
    while(true)
    {
        if(jm%2!=0 && ((hs - jm ) == 1)){
            cout<<cnt;
            return 0;
        }
        hs = nextnum(hs);
        jm = nextnum(jm);
        cnt++;
    }

}