// Authored by: prid1306
#include <iostream>
#include <stack>
#include <string>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
//중위 표기식 -> 후위 표기식으로 변환
//ABCDE
//+*-/
//ABC*+DE/-
//단순 연산자 우선순위만 따지면: ( ) * / + -
/*
우선 ()가 나오는 순간 바로 최우선순위가 되어야함.
A+B*(C-D/E) 라는 연산 결과가 존재한다면?
ABCDE/-*+
+*-/
A*B + C -> AB*C+
A + B*C*D - E
ABCD**+E-
A + B * (c * D - E)
ABCDE*-*+
최근에 나온 연산자보다 높은게 나온다면
A + B * (C - D) - E
ABCD-*+E-

A + B * (C - D * E + F) - G
ABCDE*-F+*+G-
A*B*C -> ABC**
A * (B * C - D * (E * F - G))
A * (B + C * D + E * (F - G))
ABCD*+EFG-*+*
B+C*D+E*(F-G)
//*
ABC*-DEF*G-**
괄호가 나오면 괄호가 닫히기 전 까지 전에 있던 애들 출력 대기
괄호 안에서도 이전 연산자와 우선순위 비교해서 낮으면 이전에 있던 연산자 모두 출력
*/
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