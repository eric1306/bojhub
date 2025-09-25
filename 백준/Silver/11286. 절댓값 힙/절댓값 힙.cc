// Authored by: prid1306
#include <iostream>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
class cmp{
public:
    bool operator()(int a, int b){
        if(abs(a) > abs(b)) return true;
        else if(abs(a) == abs(b)) return a > b;
        else return false;
    }
};

int main(){
    FASTIO;
    priority_queue<int, vector<int>, cmp> pq;
    int n;cin>>n;
    while(n--){
        int input;cin>>input;
        if(input != 0){
            pq.push(input);
        }else{
            if(pq.size() == 0){
                cout<<0<<'\n';
            }else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
    }
}