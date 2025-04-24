//Authored by: prid1306
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

unordered_map<string, int> umap;
string i2s[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>i2s[i];
        umap[i2s[i]] = i;
    }

    while(m--)
    {
        string query;
        cin>>query;
        if(isdigit(query[0]))
        {
            cout<<i2s[stoi(query)]<<'\n';
        }
        else
        {
            cout<<umap[query]<<'\n';
        }
    }
}