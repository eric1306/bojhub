//Authored by: prid1306
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
const string DUMMY = "1";
const int MAX = 500001;
int k,l;
string a[MAX];
unordered_map<string,int> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    cin>>k>>l;
    for(int i=0;i<l;i++)
    {
        cin>>input;
        if(s.find(input) == s.end())
        {
            s[input] = i+1;
            a[i+1] = input;
        }
        else
        {
            a[s[input]] = DUMMY;
            s.erase(input);
            s[input] = i+1;
            a[i+1] = input;
        }
    }
    int cnt = 0;

    for(int i=1;i<=l;i++)
    {
        if(cnt == k) break;

        if(a[i]!="1"){
            cout<<a[i]<<'\n';
            cnt++;
        }
        else continue;
    }
}