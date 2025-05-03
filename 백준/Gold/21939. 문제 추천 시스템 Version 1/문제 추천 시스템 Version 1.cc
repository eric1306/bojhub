//Authored by: prid1306
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define x first
#define y second

int n,p,l,m;
set<int> s[101];
int a[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p>>l;
        s[l].insert(p);
        a[p] = l;
    }
    cin>>m;
    string op;
    while(m--)
    {
        cin>>op;
        if(op == "add")
        {
            cin>>p>>l;
            s[l].insert(p);
            a[p] = l;
        }
        else if(op == "solved")
        {
            cin>>p;
            s[a[p]].erase(p);
        }
        else
        {
            int input;
            cin>>input;
            if(input == 1)
            {
                for(int i=100;i>=0;i--)
                {
                    if(s[i].size()!=0)
                    {
                        auto it = s[i].end();
                        it--;
                        cout<<*it<<'\n';
                        break;
                    }
                }
            }
            else
            {
                for(int i=0;i<=100;i++)
                {
                    if(s[i].size()!=0)
                    {
                        auto it = s[i].begin();
                        cout<<*it<<'\n';
                        break;
                    }
                }
            }
        }
    }
}