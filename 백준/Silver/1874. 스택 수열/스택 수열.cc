#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,cnt = 1;
    string ans;
    cin>>n;
    stack<int> s;
    while(n--){
        cin>>k;
        while(cnt <=k){
            s.push(cnt++);
            ans+="+\n";
        }
        if(s.top()!=k){
            cout<<"NO";
            return 0;
        }
        s.pop();
        ans+="-\n";
        
    }
    cout<<ans;
}