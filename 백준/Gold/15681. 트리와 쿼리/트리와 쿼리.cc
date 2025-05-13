//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,r,q,input;
vector<int> v[100002];
int _size[100001];
bool visit[100002];

//int p[100001];
//bool vis[100001];

void GetSubTreeSize(int node)
{
    _size[node] = 1;
    visit[node] = true;
    for(int i=0;i<v[node].size();i++)
    {
        if(!visit[v[node][i]])
        {
            GetSubTreeSize(v[node][i]);
            _size[node]+=_size[v[node][i]];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>r>>q;
    int from,to;
    for(int i=0;i<n-1;i++)
    {
        cin>>from>>to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    
    GetSubTreeSize(r);

    while(q--)
    {
        cin>>input;
        cout<<_size[input]<<'\n';
    }
    // //부모 채우기
    // queue<int> q1;
    // q1.push(r);
    // vis[r] = true;
    // while(!q1.empty())
    // {
    //     int elem = q1.front();q1.pop();
    //     for(auto c : v[elem])
    //     {
    //         if(vis[c]) continue;
    //         q1.push(c);
    //         vis[c] = true;
    //         p[c] = elem;
    //     }
    // }
    // while(q--)
    // {
    //     int ans = 0;
    //     vector<bool> visit(100001, false);
    //     cin>>input;
    //     queue<int> q2;
    //     q2.push(input);
    //     visit[input] = true;
    //     ans++;
    //     while(!q2.empty())
    //     {
    //         int elem = q2.front();q2.pop();
    //         for(auto c : v[elem])
    //         {
    //             if(visit[c] || p[elem] == c) continue;
    //             q2.push(c);
    //             visit[c] = true;
    //             ans++;
    //         }
    //     }
    //     cout<<ans<<'\n';
    // }
}