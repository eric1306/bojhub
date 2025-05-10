#include <iostream>
#include <queue>
using namespace std;
int n;
priority_queue<int> MaxHeap;
priority_queue<int,vector<int>,greater<int>> MinHeap;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int input;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        if(MinHeap.empty() && MaxHeap.empty())
        {
            MaxHeap.push(input);
            cout<<MaxHeap.top()<<'\n';
            continue;
        }
        if(!MaxHeap.empty() && !MinHeap.empty() && MinHeap.top() < input){
            MinHeap.push(input);
        }
        else{
            MaxHeap.push(input);
        }
        int rett = MaxHeap.size() - MinHeap.size();
        if(rett > 1)
        {
            MinHeap.push(MaxHeap.top());
            MaxHeap.pop();
        }
        rett = MinHeap.size() - MaxHeap.size();
        if(rett > 1)
        {
            MaxHeap.push(MinHeap.top());
            MinHeap.pop();
        }
        int ret = MinHeap.size() + MaxHeap.size();
        if(ret%2 == 0)
        {
            int ans = MaxHeap.top() > MinHeap.top() ? MinHeap.top() : MaxHeap.top();
            cout<<ans<<'\n';
        }
        else
        {
            if(MaxHeap.size() > MinHeap.size())
            {
                cout<<MaxHeap.top()<<'\n';
            }
            else
            {
                cout<<MinHeap.top()<<'\n';
            }
        }
    }
}