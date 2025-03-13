//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int v,e,f,b;
int graph_sign[20002];
bool visit[20001];

vector<int> graph[20001];

bool IsBipartiteGraph()
{
    for(int i=1;i<=v;i++)
    {
        if(!visit[i])
        {
            queue<int> q;
            q.push(i);
            visit[i] = true;
            while(!q.empty())
            {   
                int cur = q.front();q.pop();
                for(auto c : graph[cur])
                {
                    if(graph_sign[c] == graph_sign[cur]) return false;
                    if(visit[c]) continue;
                    visit[c] = true;
                    q.push(c);
                }
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>k;
    while(k--)
    {
        cin>>v>>e;
        fill(graph_sign+1, graph_sign+v+1,-1);
        fill(visit+1,visit+v+1,false);
        for(int i=1;i<=v;i++) 
            graph[i].clear();
        for(int i=0;i<e;i++)
        {
            cin>>f>>b;
            graph[f].push_back(b);
            graph[b].push_back(f);
        }
        //signal 배열 채우기.
        for(int i=1;i<=v;i++)
        {
            if(graph_sign[i]==-1)
            {
                queue<int> q;
                q.push(i);
                graph_sign[i] = 1;
                while(!q.empty())
                {
                    int cur = q.front();q.pop();
                    for(auto c : graph[cur])
                    {
                        if(graph_sign[c]!=-1) continue;
                        graph_sign[c] = 1-graph_sign[cur];
                        q.push(c);
                    }
                }
            }
        }
        //채운 배열 값을 통해서 값 검증하기.
        if(IsBipartiteGraph()) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}