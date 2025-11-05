// Authored by: prid1306
#include <iostream>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
#define x first
#define y second
int a,b;
int ans = -1;
int op1(int input){
    return input/2;
}
int op2(int input){
    return (input-1)/10;
}
int main(){
    FASTIO;
    cin>>a>>b;
    queue<pair<int,int>> q;
    q.push({b, 1});
    while(!q.empty())
    {
        auto p = q.front();q.pop();
        if(p.x == a){
            cout<<p.y<<'\n';
            return 0;
        }
        if(p.x > a){
            if(p.x%2 == 0)
                q.push({op1(p.x), p.y + 1});

            if(p.x % 10 == 1)
                q.push({op2(p.x), p.y + 1});
        }
    }
    cout<<-1<<'\n';
}