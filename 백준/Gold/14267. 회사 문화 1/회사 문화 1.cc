//Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<int> parent(100'001, 0);
vector<int> ans(100'001, 0);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int input;
        cin>>input;
        parent[i] = input;
    }
    
    int num, praise;
    while(m--)
    {
        cin>>num>>praise;
        ans[num] += praise;
    }
    //타고 올라가면서 나의 부모가 칭찬 받으면 더해서 합산값 출력
    cout<<0<<' ';
    for(int i=2;i<=n;i++)
    {
        ans[i] += ans[parent[i]];
        cout<<ans[i]<<' ';
    }
} 