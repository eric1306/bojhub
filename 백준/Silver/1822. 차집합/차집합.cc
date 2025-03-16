//Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a,b;
int na[500001];
int nb[500001];
vector<int> ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    for(int i=0;i<a;i++) cin>>na[i];
    for(int i=0;i<b;i++) cin>>nb[i];
    sort(na,na+a);
    sort(nb,nb+b);
    for(int i=0;i<a;i++)
    {
        if(!binary_search(nb,nb+b,na[i]))
        {
            ans.push_back(na[i]);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto c : ans)
    {
        cout<<c<<' ';
    }

}