//Authored by: prid1306
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#define x first
#define y second

using namespace std;
int n;
vector<pair<int,int>> a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int f,b;
    for(int i=0;i<n;i++)
    {
        cin>>f>>b;
        a.push_back(make_pair(b,f));
    }
    sort(a.begin(),a.end());
    int cnt = 1,curend = a.front().x;
    for(int i=1;i<a.size();i++)
    {
        if(a[i].y < curend) continue;
        cnt++;curend = a[i].x;
    }
    cout<<cnt;

}