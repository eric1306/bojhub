#include <iostream>
#include <string>
using namespace std;
int dat[2000001];
int head = 0;
int unused = 0;

void push(int t){
    dat[unused++] = t;
}

void pop(){
    if(head == unused) cout<<-1<<'\n';
    else cout<<dat[head++]<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        string op;
        cin>>op;
        if(op == "push"){
            int t;
            cin>>t;
            push(t);
        }else if(op == "pop"){
            pop();
        }else if(op == "front"){
            if(head == unused) cout<<-1<<'\n';
            else cout<<dat[head]<<'\n';
        }else if(op == "back"){
            if(head == unused) cout<<-1<<'\n';
            else cout<<dat[unused-1]<<'\n';
        }else if(op == "size"){
            cout<<unused - head<<'\n';
        }else if(op == "empty"){
            if(head == unused) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
}