// Authored by: prid1306
#include <iostream>
#include <vector>
#include <stack>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using pii = pair<int,int>;
vector<pii> adjacent[100'001];
int n;
pii DFS(int st)
{
    vector<bool> visit(n + 1 ,false);
    pii ans = {-1, -1}; //점, dist
    stack<pii> s;
    s.emplace(st, 0);
    visit[st] = true;
    while(!s.empty())
    {
        auto [node, dist] = s.top(); s.pop();
        for(auto [nNode, nDist] : adjacent[node])
        {
            if(visit[nNode]) continue;
            if(ans.second < nDist + dist)
            {
                ans = {nNode, nDist + dist};
            }
            visit[nNode] = true;
            s.emplace(nNode, nDist + dist);
        }
    }
    return ans;
}
int main(){
    FASTIO;
    cin>>n;
    for(int i=0;i<n;++i){
        int input,node,value;
        cin>>input;
        cin>>node;
        while(node != -1)
        {
            cin>>value;
            adjacent[input].emplace_back(node, value);
            cin>>node;
        }
    }
    auto [node, dist] = DFS(1);
    auto [dummy, ans] = DFS(node);
    cout<<ans;
}