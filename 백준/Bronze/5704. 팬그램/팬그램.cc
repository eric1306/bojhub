// Authored by: prid1306
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main(){
    FASTIO;
    vector<bool> isused(26, false);
    while(true)
    {
        fill(isused.begin(), isused.end(), false);
        string s;
        getline(cin, s);
        if(s == "*") return 0;
        //cout<<s<<'\n';
        for(char c : s)
        {
            //cout<<"this word: "<<c<<'\n';
            if(c == ' ') continue;
            isused[c - 'a'] = true;
        }
        int cnt = std::count(isused.begin(), isused.end(), false);
        if(cnt == 0) cout<<"Y"<<'\n';
        else cout<<"N"<<'\n';
    }
}