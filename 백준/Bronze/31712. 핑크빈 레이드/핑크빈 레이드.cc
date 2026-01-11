// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int c[3];
int d[3];
int h;
int t[3];
int main(){
    FASTIO;
    for(int i=0;i<3;i++)
    {
        cin>>c[i]>>d[i];
        t[i] = c[i];
    }
    cin>>h;
    int time = 0;
    while(true)
    {
        for(int i=0;i<3;i++)
        {
            if(t[i] == c[i])
            {
                h -= d[i];
                t[i] = 0;
            }
        }
        if(h <= 0)
        {
            cout<<time;
            break;
        }
        time++;
        for(int i=0;i<3;i++){
            t[i]++;
        }
    }
}