#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int a1[1000001];
int a2[1000001];
int ans[2000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,tmp;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a1[i];
    for(int i=0;i<m;i++) cin>>a2[i];
    int st1=0,st2=0,cnt=0;
    while(st1 < n||st2 < m){
        if(st1 == n){
            ans[cnt++] = a2[st2++];
        }else if(st2 == m){
            ans[cnt++] = a1[st1++];
        }else if(a1[st1] < a2[st2]){
            ans[cnt++] = a1[st1++];
        }else{
            ans[cnt++] = a2[st2++];
        }
    }
    for(int i=0;i<n+m;i++) cout<<ans[i]<<' ';
}