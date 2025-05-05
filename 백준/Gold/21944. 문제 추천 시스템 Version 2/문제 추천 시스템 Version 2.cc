//Authored by: prid1306
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
int n,m;
pair<int,int> level[100'002];
set<int> s[101][101]; //[분류][난이도]
set<int> sl[101]; //[난이도]

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int p,l,g;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p>>l>>g;
        s[g][l].insert(p);
        sl[l].insert(p);
        level[p] = {g, l};
    }
    cin>>m;
    string op;
    while(m--)
    {
        cin>>op;
        if(op == "recommend")
        {
            int x;
            cin>>g>>x;
            if(x == 1)
            {
                for(int i=100;i>=0;i--)
                {
                    if(s[g][i].empty())
                        continue;
                    auto it = s[g][i].end();
                    it--;
                    cout<<*it<<'\n';
                    break;
                }
            }
            else // x == -1
            {
                for(int i=0;i<101;i++)
                {
                    if(s[g][i].empty())
                        continue;
                    auto it = s[g][i].begin();
                    cout<<*it<<'\n';
                    break;
                }
            }
        }
        else if(op == "recommend2")
        {
            int x;
            cin>>x;
            if(x == 1)
            {
                for(int i=100;i>=0;i--)
                {
                    if(sl[i].empty())
                        continue;
                    auto it = sl[i].end();
                    it--;
                    cout<<*it<<'\n';
                    break;
                }
            }
            else
            {
                for(int i=0;i<101;i++)
                {
                    if(sl[i].empty())
                        continue;
                    auto it = sl[i].begin();
                    cout<<*it<<'\n';
                    break;
                }
            }
        }
        else if(op == "recommend3")
        {
            int x,ans = -1;
            cin>>x>>l;
            if(x == 1)
            {
                for(int i=l;i<101;i++)
                {
                    if(sl[i].empty())
                        continue;
                    auto it = sl[i].begin();
                    ans = *it;
                    break;
                }
                cout<<ans<<'\n';
            }
            else
            {
                for(int i=l-1;i>=0;i--)
                {
                    if(sl[i].empty())
                        continue;
                    auto it = sl[i].end();
                    it--;
                    ans = *it;
                    break;
                }
                cout<<ans<<'\n';
            }
        }
        else if(op == "add")
        {
            cin>>p>>l>>g;
            s[g][l].insert(p);
            sl[l].insert(p);
            level[p] = {g, l};
        }
        else //solved
        {
            cin>>p;
            pair<int,int> selectlevel = level[p];
            auto it = s[selectlevel.first][selectlevel.second].find(p);
            s[selectlevel.first][selectlevel.second].erase(it);

            it = sl[selectlevel.second].find(p);
            sl[selectlevel.second].erase(it);
            level[p] = {0, 0};
        }
    }
} 