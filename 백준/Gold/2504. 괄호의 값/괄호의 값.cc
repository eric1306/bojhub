#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string n;
    int multi = 1,ans=0,cnt = 0;
    char before;
    cin>>n;
    stack<int> s;
    before = n[0];
    for(char c : n){
        if(c == '(' || c == '['){
            s.push(c);
            c == '(' ? multi*=2 : multi *=3;
        }else{ //c is ) or ]
            if(c == ')'){
                /*예외처리
                1. 배열이 빈 경우
                2. 앞에 [ 인 경우
                */
                if(s.empty()){
                    ans = 0;
                    break;
                }else{
                    if(s.top() == '['){
                        ans = 0;
                        break;
                    }
                }

                if(before == '(') ans+=multi;
                s.pop();
                multi/=2;
            }else{ /*c == ]*/
                /*예외처리*/
                if(s.empty()){
                    ans = 0;
                    break;
                }else{
                    if(s.top() == '('){
                        ans = 0;
                        break;
                    }
                }

                if(before == '[') ans+=multi;
                s.pop();
                multi/=3;
            }
        }
        before = c;
    }
    if(!s.empty()) ans = 0;
    cout<<ans;
    
}