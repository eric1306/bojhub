//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[101];
int visit[101];
int n,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int f,b,ans = 0;
    for(int i=0;i<m;i++){
        cin>>f>>b;
        v[f].push_back(b);
        v[b].push_back(f);
    }
    queue<int> q;
    q.push(1);
    visit[1] = true;
    while(!q.empty())
    {
        int cur = q.front();q.pop();
        for(auto c : v[cur])
        {
            if(visit[c]) continue;
            q.push(c);
            visit[c] = true;
            ans++;
        }
    }
    cout<<ans;
}