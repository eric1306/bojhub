// Authored by: prid1306
// BOJ 2504
#include <iostream>
#include <stack>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main(){
    FASTIO;
    stack<char> s;
    string input;
    cin>>input;
    int ans = 0,mul = 1;
    for(int i=0;i<input.size();i++)
    {
        if(input[i] == '('){
            s.push(input[i]); mul*=2;
        }else if(input[i] == '[') {
            s.push(input[i]); mul*=3;
        }
        else if(input[i] == ')'){
            if(s.empty() || s.top() != '('){cout<<0;return 0;}
            s.pop();
            if(input[i-1] == '(') ans+=mul;
            mul/=2;
        }else{
            if(s.empty() || s.top() != '['){cout<<0;return 0;}
            s.pop();
            if(input[i-1] == '[') ans+=mul;
            mul/=3;
        }

    }
    if(!s.empty()){ cout<<0;return 0;}
    cout<<ans;
}