#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string n;
    bool flag;
    stack<int> s;
    getline(cin,n);
    while(n!="."){
        flag = true;

        for(auto t : n){
            if(t == '(' || t == '['){
                s.push(t);
            }else if(t == ')'){
                if(s.empty()) 
                    flag = false;
                else{
                    if(s.top() == '('){
                        s.pop();
                    }else 
                        flag = false;
                }
            }else if(t == ']'){
                if(s.empty()) 
                    flag = false;
                else{
                    if(s.top() == '['){
                        s.pop();
                    }else 
                        flag = false;
                }
            }else if(t == '.') break;
            else continue;
        }
        if(flag && s.empty()) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';

        while(!s.empty()) s.pop();
        //다음값 입력 받기
        getline(cin,n);
    }
}