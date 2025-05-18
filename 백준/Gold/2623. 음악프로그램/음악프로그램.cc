//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
int adj[1001];
vector<int> p[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int input,cnt;
    
    for(int i=0;i<m;i++)
    {
        int prev = -1;
        cin>>cnt;
        for(int j = 0;j<cnt;j++)
        {
            cin>>input;
            if(prev == -1){
                prev = input;
                continue;
            }
            adj[input]++;
            p[prev].push_back(input);
            prev = input;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(adj[i] == 0) q.push(i);
    }
    queue<int> result;
    while(!q.empty())
    {
        int cur = q.front();q.pop();
        result.push(cur);
        for(int nxt : p[cur])
        {
            adj[nxt]--;
            if(adj[nxt] == 0) q.push(nxt);
        }
    }
    if(result.size()!=n)
        cout<<0;
    else{
        while(!result.empty()){
            cout<<result.front()<<'\n';
            result.pop();
        }
    }
}