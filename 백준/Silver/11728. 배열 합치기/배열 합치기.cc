#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> v1,v2, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,tmp;
    cin>>n>>m;
    while(n--){
        cin>>tmp;
        v1.push_back(tmp);
    }
    while(m--){
        cin>>tmp;
        v2.push_back(tmp);
    }
    while(v2.size()|| v1.size()){
        if(v2.size() == 0){
            ans.push_back(v1.front());
            v1.pop_front();
            continue;
        }
        if(v1.size() == 0){
            ans.push_back(v2.front());
            v2.pop_front();
            continue;
        }
        if(v1.front() < v2.front()){
            ans.push_back(v1.front());
            v1.pop_front();
            continue;
        }else{
            ans.push_back(v2.front());
            v2.pop_front();
            continue;
        }
    }
    for(auto c : ans) cout<<c<<' ';
}