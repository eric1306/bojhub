// Authored by: prid1306
// BOJ 15787
#include <iostream>
#include <unordered_set>
using namespace std;
int a[100001];
int n,m;
unordered_set<int> s;
const int checker = 0xfff00000;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int op,train,sit;
        cin>>op;
        if(op == 1){
            cin>>train>>sit;
            sit--;
            if(!(a[train] & 1<<sit)){
                a[train] |=1<<sit;
            }
        }else if(op == 2){
            cin>>train>>sit;
            sit--;
            if(a[train] & 1<<sit){
                a[train] -= 1<<sit;
            }
        }else if(op == 3){
            cin>>train;
            a[train] <<= 1;
            if(a[train] & checker){
                a[train] -= 1<<20;
            }
        }else{
            cin>>train;
            a[train] >>= 1;
        }
    }
    for(int i=1;i<=n;i++){
        if(s.find(a[i]) == s.end()){
            s.insert(a[i]);
        }
    }
    cout<<s.size();
} 