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
    cin>>s>>w;
    string ans;
    int ssize = s.size();
    int wsize = w.size();
    stack<char> st;
    for(char ch : s)
    {
        st.push(ch);
        if(st.size() >= w.size() && ch == w[wsize - 1])
        {
            string tmp = "";
            bool IsW = true;
            for(int j=wsize - 1;j >= 0; --j)
            {
                if(st.top() && st.top() == w[j])
                {
                    tmp += st.top();
                    st.pop();
                    continue;
                }
                else{
                    IsW = false;
                    break;
                }
            }
            if(IsW == false)
            {
                reverse(tmp.begin(),tmp.end());
                for(auto elem : tmp)
                {
                    st.push(elem);
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