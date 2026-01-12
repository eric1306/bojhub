// Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
string printCommunity(int idx)
{
    switch(idx)
    {
        case 0: return "PROBRAIN";
        case 1: return "GROW";
        case 2: return "ARGOS";
        case 3: return "ADMIN";
        case 4: return "ANT";
        case 5: return "MOTION";
        case 6: return "SPG";
        case 7: return "COMON";
        case 8: return "ALMIGHTY";
    }
}
int main(){
    FASTIO;
    int _max = -1;
    int maxNum = 0;
    int n;cin>>n;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<n;j++)
        {
            int input;cin>>input;
            if(_max < input)
            {
                _max = input;
                maxNum = i;
            }
        }
    }
    cout<<printCommunity(maxNum);
}