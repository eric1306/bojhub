//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int _min = 51;
vector<int> v[51];
vector<pair<int,int>> ans_v;
int chon[51];
int ans[51];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int f,b;
    cin>>f>>b;
    while(f!=-1 && b!=-1)
    {
        v[f].push_back(b);
        v[b].push_back(f);
        cin>>f>>b;
    }
    for(int i=1;i<=n;i++)
    {
        queue<int> q;
        fill(chon, chon+n+1,-1);
        chon[i] = 0;
        for(auto c : v[i])
        {
            chon[c] = 1;
            q.push(c);
        }
        while(!q.empty())
        {
            int cur = q.front();q.pop();
            for(auto c : v[cur])
            {
                if(chon[c] != -1)continue;
                chon[c] = chon[cur] + 1;
                q.push(c);
            }
        }
        int _max = -1;
        for(int i=1;i<=n;i++)
        {
            if(_max < chon[i]) _max = chon[i];
        }
        if(_max < _min) _min = _max;
        ans_v.push_back({i,_max});
    }
    int cnt = 0;
    for(auto c : ans_v)
    {
        if(c.second == _min) cnt++;
    }
    cout<<_min<<' '<<cnt<<'\n';
    for(auto c : ans_v)
    {
        if(c.second == _min) cout<<c.first<<' ';
    }
}