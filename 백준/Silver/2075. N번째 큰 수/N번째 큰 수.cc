//Authored by prid1306
#include <iostream>
#include <queue>
using namespace std;
/*
문제 제한이 12MB
int 2개 -> 8byte
priority_queue는 4byte짜리 원소 저장.
1500 * 1500 = 2'250'000
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,input;
    priority_queue<int,vector<int>, greater<int>> pq;
    cin>>n;
    for(int i=0;i<n*n;i++)
    {
        cin>>input;
        pq.push(input);
        if(pq.size() > n)
        {
            pq.pop();
        }
    }
    
    cout<<pq.top();
}