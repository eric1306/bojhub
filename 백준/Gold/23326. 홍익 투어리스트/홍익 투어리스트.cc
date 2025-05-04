//Authored by: prid1306
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#define x first
#define y second
using namespace std;
int n,q;
set<int> s[2]; //0은 명소X, 1은 명소 list
int a[500001];
int dohyun;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]) s[1].insert(i);
        else s[0].insert(i);
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
                s[1].erase(s[1].find(input));
                s[0].insert(input);
                a[input] = 0;
            }
            else
            {
                //명소 등록
                s[0].erase(s[0].find(input));
                s[1].insert(input);
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
            if(s[1].empty())
            {
                cout<<-1<<'\n';
                continue;
            }
    
            int ans = n;
    
            auto it = s[1].lower_bound(dohyun);
    
            if(it != s[1].end())
            {
                // 도현이 위치 이후에 있는 명소까지의 거리
                ans = *it - dohyun;
            }
            else
            {
                // 도현이 위치 이후에 명소가 없다면, 원형으로 돌아가 첫 번째 명소까지의 거리
                ans = n - dohyun + *s[1].begin();
            }
    
            cout << ans << '\n';
        }
    }
} 