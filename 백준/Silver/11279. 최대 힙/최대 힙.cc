// Authored by: prid1306
#include <iostream>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n;
priority_queue<int> pq;
int main(){
    FASTIO;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int input;cin>>input;
        if(input == 0)
        {
            if(pq.size() == 0)
            {
                cout<<0<<'\n';
            }
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(input);
        }
    }
}