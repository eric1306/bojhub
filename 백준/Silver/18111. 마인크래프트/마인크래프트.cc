// Authored by: prid1306
#include <iostream>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,m,b;
int a[257];
int ans = 0xfffffff;
int ansheight = 0;

int main(){
    FASTIO;
    cin>>n>>m>>b;
    int _min = 0x7fffffff;
    int _max = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int input;cin>>input;
            ++a[input];
            _min = min(_min, input);
            _max = max(_max, input);
        }
    }

    for(int i=_min; i<=_max;++i)//최대 256
    {
        int tmpsum = 0,tmpb = 0;
        for(int j=0;j<=256;++j)// 256
        {
            if(a[j] == 0) continue;
            if(j > i)
            {
                tmpb += (j - i) * a[j];
                tmpsum += 2 * (j - i) * a[j];
            }
            else if(j < i)
            {
                tmpb -= (i - j) * a[j];
                tmpsum += (i - j) * a[j];
            }
        }
        if(tmpsum <= ans && tmpb + b >= 0)
        {
            ans = tmpsum;
            ansheight = i;
        }
    }
    cout<<ans<<' '<<ansheight;
}