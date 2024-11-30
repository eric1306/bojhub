#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    list<int> l;
    for(int i=1;i<=n;i++){
        l.push_back(i);
    }
    
    auto t = l.begin();
    cout<<'<';
    while(!l.empty()){
        for(int i=0;i<k;i++){
            if(t==l.end()) t = l.begin();
            t++;
        }
        //1 2 3 4 5 6 7
        if(t==l.begin()) t = l.end();
        t--;
        cout<<*t;
        t = l.erase(t);
        
        if(!l.empty())cout<<", ";
        else cout<<'>';
    }
}