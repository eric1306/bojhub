// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
/*
게이트 최대 100'000
비행기 최대 100'000
*/
int main(){
    FASTIO;
    int g,p;
    cin>>g>>p;
    vector<int> v(p);
    vector<bool> isfill(g, false);
    map<int, int> m;
    for(int i=0;i<p;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<g;i++)
    {
        m[i] = i;
    }
    int ans = 0;
    for(int i=0;i<p;i++)
    {
        bool bflag = true;
        int st = v[i] - 1;
        for(int j=m[v[i] - 1]; j>= 0; j--)
        {
            if(!isfill[j])
            {
                bflag = false;
                isfill[j] = true;
                m[v[i] - 1] = j-1;
                ans++;
                break;
            }
        }
        if(bflag)
        {
            break;
        }
    }
    cout<<ans;
}