//Authored by: prid1306
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string misa[1001];
string n;
bool cmp(string a, string b){
    int _a=0,_b=0;
    while(_a < a.size() || _b < b.size())
    {
        if(a[_a]!=b[_b]){
            return a[_a] < b[_b];
        }
        _a++;_b++;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n.size();i++){
        misa[i] = n.substr(i,n.size()-i);
    }
    sort(misa,misa+n.size(), &cmp);
    for(int i=0;i<n.size();i++) cout<<misa[i]<<'\n';
}