//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,ans = 0;
vector<int> v[501];
int visit[501];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int f,b;
    for(int i=0;i<m;i++)
    {
        cin>>f>>b;
        v[f].push_back(b);
        v[b].push_back(f);
    }
    queue<pair<int,int>> q;
    q.push({1,0});
    visit[1] = true;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();q.pop();
        for(auto c : v[cur.first])
        {
            if(visit[c] || cur.second > 1) continue;
            q.push({c, cur.second+1});
            visit[c] = true;
            ans++;
        }
    }
    cout<<ans;
}