//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<int> v[1001];
int visit[1001];
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
    fill(visit,visit+n,0);
    int ans = 0;
    for(int i=1;i<=n;i++)
    {    
        if(!visit[i])
        {
            ans++;
            queue<int> q;
            q.push(i);
            visit[i] = 1;
            while(!q.empty())
            {
                int cur = q.front();
                q.pop();
                for(auto c : v[cur])
                {
                    if(visit[c]) continue;
                    visit[c] = 1;
                    q.push(c);
                }
            }
        }
    }
    cout<<ans;
}