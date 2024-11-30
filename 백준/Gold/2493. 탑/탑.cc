#include <iostream>
#include <stack>
using namespace std;

int n;
stack<pair<int,int>> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    s.push({100000001,0});    
    cin>>n;

    for(int i=1;i<=n;i++){
        int h;
        cin>>h;
        while(s.top().first < h)
            s.pop();
        cout<<s.top().second<<" ";
        s.push({h, i});
    }

}