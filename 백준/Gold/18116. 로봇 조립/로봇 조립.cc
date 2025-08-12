// Authored by: prid1306
#include <iostream>
#include <vector>
using namespace std;
//최적화를 위해 트리의 높이를 고려했지만, 이제는 트리의 하위 원소로 몇 가지가 존재하는지 살펴봐야함.
vector<int> p(1'000'001, -1);
vector<int> cnt(1'000'001, 1);

int find(int x){
    if(p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
        return false;
    if(p[v] < p[u])
        swap(u,v);
    if(p[u] == p[v])
        p[u]--;
    p[v] = u;
    cnt[u] += cnt[v];
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    while(n--)
    {
        char input;cin>>input;
        if(input == 'I')
        {
            int a,b;cin>>a>>b;
            uni(a,b);
        }
        else
        {
            int a;cin>>a;
            cout<<cnt[find(a)]<<'\n';
        }
    }
} 