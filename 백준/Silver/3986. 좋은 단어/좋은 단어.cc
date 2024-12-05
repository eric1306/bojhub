#include <iostream>
#include <stack>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,ans = 0;
    cin>>n;
    while(n--){
        stack<char> s;
        string n;
        cin>>n;
        for(char c : n){
            if(s.empty()) s.push(c);
            else{
                if(c == 'A'){
                    if(s.top() == 'A'){
                        s.pop();
                    }else{ /*s.top() == 'B'*/
                        s.push(c);
                    }
                }else{ /*c == 'B'*/
                    if(s.top() == 'B'){
                        s.pop();
                    }else{
                        s.push(c);
                    }
                }
            }
        }
        if(s.empty()){
            ans++;
        }
    }
    cout<<ans;
}