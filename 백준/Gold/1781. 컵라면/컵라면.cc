//Authored by: prid1306
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
결국 중요한 것은, 컵라면을 많이 주는 데드라인 적은 문제를 빨리 풀어버린는 것.
*/
#define x first
#define y second

int n;
priority_queue<int> pq;
vector<vector<int>> v(200'001);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int deadline,cup;
    for(int i=0;i<n;i++)
    {
        cin>>deadline>>cup;
        v[deadline].push_back(cup);
    }
    int ans = 0;
    for(int i=200'000;i>0;i--)
    {
        for(int j : v[i])
        {
            pq.push(j);
        }
        if(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
    }

    cout<<ans;
}