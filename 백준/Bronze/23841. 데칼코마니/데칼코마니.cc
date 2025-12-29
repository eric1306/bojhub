// Authored by: prid1306
#include <iostream>
#include <vector>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
string a[51];
vector<pair<int,int>> v;
int main(){
    FASTIO;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(int j=0;j<m;j++)
        {
            if(a[i][j]!='.')
            {
                v.emplace_back(i, j);
            }
        }
    }
    for(const auto& elem : v)
    {
        a[elem.first][m - 1 - elem.second] = a[elem.first][elem.second];
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<'\n';
    }
}