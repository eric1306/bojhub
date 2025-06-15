//Authored by: prid1306
#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string dm,word;
    getline(cin,dm);
    getline(cin, word);
    int pos = 0,ans = 0;
    while(pos < dm.size())
    {
        int vis = dm.find(word, pos);
        if(vis == -1) pos = dm.size();
        else
        {
            ans++;
            pos = vis + word.size();
        }
    }
    cout<<ans;
} 