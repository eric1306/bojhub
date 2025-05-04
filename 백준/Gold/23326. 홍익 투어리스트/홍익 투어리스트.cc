//Authored by: prid1306
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#define x first
#define y second
using namespace std;
int n,q;
set<int> s; //0은 명소X, 1은 명소 list
int a[500001];
int dohyun;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]) s.insert(i);
    }
    int op,input;
    while(q--)
    {
        cin>>op;
        if(op == 1)
        {
            cin>>input;
            input--;
            if(a[input])
            {
                //명소 등록 해제
                s.erase(s.find(input));
                a[input] = 0;
            }
            else
            {
                //명소 등록
                s.insert(input);
                a[input] = 1;
            }
        }
        else if(op == 2)
        {
            cin>>input;
            dohyun = (dohyun + input) % n;
        }
        else
        {
            if(s.empty())
            {
                cout<<-1<<'\n';
                continue;
            }
            int ans = n;
            //명소인 곳 중에서 dohyun의 idx보다 높거나 같은 애를 찾아야 하니까
            auto it = s.lower_bound(dohyun);
            //도현 이후 && 도현 이전 분리.
            if(it != s.end())
            {
                ans = *it - dohyun;
            }
            else
            {
                ans = n - dohyun + *s.begin();
            }
            cout << ans << '\n';
        }
    }
} 