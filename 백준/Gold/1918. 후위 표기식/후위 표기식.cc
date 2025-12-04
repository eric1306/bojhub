// Authored by: prid1306
#include <iostream>
#include <stack>
#include <string>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
stack<char> op;
string s;
string ans = "";

short InBracket = 0;
char currentOp = 0;
short currentOpBracket = 0;

bool IsOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

bool IsLowerThanCurrentOp(char c)
{
    if(currentOp == '*' || currentOp == '/')
    {
        if(c == '+' || c == '-' || c == '*' || c == '/') return true;
    }
    else if(currentOp == '+' || currentOp == '-')
    {
        if(c == '+' || c == '-') return true;
    }
    return false;
}

int main(){
    FASTIO;
    cin>>s;
    for(char elem : s)
    {
        if(IsOperator(elem))
        {
            if(elem == '(' && InBracket == 0)
            {
                ++InBracket;
                op.push('(');
            }
            else if(elem == ')')
            {
                --InBracket; // 괄호 종료
                --currentOpBracket;
                while(op.top()!= '(') //괄호 안에 나왔던 연산자들 모두 포함시키기.
                {
                    ans += op.top(); op.pop();
                }
                op.pop();
                if(!op.empty())
                {
                    currentOp = op.top();
                    currentOpBracket = InBracket;
                }
            }
            else //일반 연산자
            {
                if(currentOp == 0)
                {
                    currentOp = elem;
                    currentOpBracket = InBracket;
                    op.push(elem);
                    continue;
                }
                if(IsLowerThanCurrentOp(elem) && currentOpBracket >= InBracket)
                {
                    while(!op.empty() && op.top()!='(' && IsLowerThanCurrentOp(elem))
                    {
                        ans+=op.top();op.pop();
                        if(!op.empty())
                            currentOp = op.top();
                    }
                    op.push(elem);
                    currentOp = elem;
                    currentOpBracket = InBracket;
                }
                else if(currentOpBracket < InBracket)
                {
                    op.push(elem);
                    currentOp = elem;
                    currentOpBracket = InBracket;
                }
                else{
                    op.push(elem);
                    currentOp = elem;
                    currentOpBracket = InBracket;
                }
            }
        }
        else //알파벳이면 그냥 문자열에 추가하기.
        {
            ans += elem;
        }
    }
    while(!op.empty())
    {
        ans+= op.top(); op.pop();
    }
    cout<<ans<<'\n';
}