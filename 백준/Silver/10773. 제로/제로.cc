#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    int k,p,sum = 0;
    cin>>k;
    while(k--){
        cin>>p;
        if(!p && s.size()!=0) s.pop();
        else s.push(p);
    }
    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }
    cout<<sum;
}