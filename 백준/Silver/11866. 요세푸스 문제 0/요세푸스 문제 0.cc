// Authored by: prid1306
#include <iostream>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,k;
deque<int> dq;
int main(){
    FASTIO;
    cin>>n>>k;
    for(int i=1;i<=n;i++){ //1 - n 까지 저장
        dq.push_back(i);
    }
    int cnt = 1;
    cout<<"<";
    while(!dq.empty())
    {
        if(cnt%k == 0){
            if(dq.size() == 1) cout<<dq.front();
            else cout<<dq.front()<<", ";
            dq.pop_front();
            cnt = 1;
        }else{
            dq.push_back(dq.front());
            dq.pop_front();
            cnt++;
        }
    }
    cout<<">";
}