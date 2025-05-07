//Authored by: prid1306
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int input;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        pq.push(input);
    }
    int ans = 0;
    while(pq.size() > 1)
    {
        int a = pq.top();pq.pop();
        int b = pq.top();pq.pop();
        ans += a+b;
        pq.push(a+b);
    }
    cout<<ans;
} 