//Authored by: prid1306
#include <iostream>
#include <queue>
using namespace std;

#define x first
#define y second

int n,m;
vector<int> v[501];

int CheckTreeIsExits()
{
    int TreeNum = 0;
    vector<int> vis(n+1, 0); //탐색 여부 체크하는 vector 배열
    for(int i=1;i<vis.size();i++)
    {
        if(vis[i] == 0) //방문한 적이 없다면 트리 탐색 진행
        {
            queue<int> q;
            q.push(i);
            vis[i] = i;
            bool bflag = true;
            while(!q.empty())
            {
                int p = q.front();q.pop();
                for(auto c : v[p])
                {
                    if(vis[c])
                    {
                        if(c != vis[p] || c == p)
                            bflag = false;

                        continue;
                    }
                    q.push(c);
                    vis[c] = p;
                }
            }
            if(bflag)
                TreeNum++;
        }
    }
    return TreeNum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int count = 1;
    cin>>n>>m;
    while(n > 0)
    {
        int from, to;
        for(int i=0;i<m;i++)
        {
            cin>>from>>to;
            v[from].push_back(to);
            v[to].push_back(from);
        }
        int ret = CheckTreeIsExits();
        switch(ret)
        {
            case 0:
                cout<<"Case "<<count<<": No trees.\n";
                break;
            case 1:
                cout<<"Case "<<count<<": There is one tree.\n";
                break;
            default:
                cout<<"Case "<<count<<": A forest of "<<ret<<" trees.\n";
                break;
        }
        count++;
        for(int i=1;i<=n;i++) v[i].clear();
        cin>>n>>m;
    }
    
} 