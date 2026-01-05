// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main(){
    FASTIO;
    int day, a, b; cin>>day>>a>>b;
    int gonion = 1, bonion = 1;
    while(day--)
    {
        gonion+=a; bonion+=b;
        if(gonion < bonion)
        {
            std::swap(gonion, bonion);
        }
        else if(gonion == bonion)
        {
            bonion--;
        }
    }
    cout<<gonion<<' '<<bonion<<'\n';
}