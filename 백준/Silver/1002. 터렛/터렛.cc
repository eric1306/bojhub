// Authored by: prid1306
#include <iostream>
#include <cmath>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
inline float GetDist(int x1, int y1, int x2, int y2)
{
    long long ret = ((x1 - x2)*(x1 - x2) + (y1 - y2) * (y1 - y2));
    return sqrt(ret);
}
int main(){
    FASTIO;
    int t;
    float x1,y1,r1,x2,y2,r2;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        if(x1 == x2 && y1 == y2)
        {
            if(r1 == r2) cout<<-1<<'\n';
            else cout<<0<<'\n';
        }
        else
        {
            float dist = GetDist(x1, y1, x2, y2);
        if(dist < r1 || dist < r2)
        {
            int distC = abs(r1 - r2);
            if(dist > distC)
            {
                cout<<2<<'\n';
            }
            else if(dist == distC)
            {
                cout<<1<<'\n';
            }
            else
            {
                cout<<0<<'\n';
            }
        }
        else
        {
            if(dist < r1 + r2)
            {
                cout<<2<<'\n';
            }
            else if(dist == (r1 + r2))
            {
                cout<<1<<'\n';
            }
            else
            {
                cout<<0<<'\n';
            }
        }
        }
    }
}