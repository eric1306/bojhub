// Authored by: prid1306
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
string s,w;

int main(){
    FASTIO;
    /*
    문자열 길이 1-1'000'000
    폭발 문자열의 길이는 1-36
    일반 find 위치 탐색 + 문자열 탐색은 시간복잡도 초과
    -> O(SW) 는 통과할 것
    s문자열 전체를 for문을 돌면서: O(S)
        마지막 문자라면 임시 stack 만들어서 하나씩 조사해보기
        이렇게 w첫번째 문자까지 맞다면 임시 스택 clear 시키면서 마무리 아니라면 stack 내역 복구
    */
    cin>>s>>w;
    string ans;
    int ssize = s.size();
    int wsize = w.size();
    stack<char> st;
    for(int i = 0; i < ssize; ++i)
    {
        st.push(s[i]);
        if(st.size() >= w.size() && s[i] == w[wsize - 1])
        {
            stack<char> tmp;
            bool IsW = true;
            for(int j=wsize - 1;j >= 0; --j)
            {
                if(st.empty())
                {
                    IsW = false;
                    break;
                }
                if(st.top() == w[j])
                {
                    tmp.push(st.top());
                    st.pop();
                    continue;
                }
                else
                {
                    IsW = false;
                    break;
                }
            }
            if(IsW == false)
            {
                while(!tmp.empty())
                {
                    st.push(tmp.top());
                    tmp.pop();
                }
            }
        }
    }
    //답 추출하는 부분
    while(!st.empty()){
        ans += st.top(); st.pop();
    }
    reverse(ans.begin(), ans.end());
    if(ans.size() == 0) cout<<"FRULA";
    else cout<<ans<<'\n';
}