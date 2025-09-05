// Authored by: prid1306
// BOJ 2294
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int d[100001];
set<int> s;
const int INF = 1e9;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(d, d+10001, INF);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int coin;
        cin>>coin;
        s.insert(coin);
        d[coin] = 1;
    }
    for(int i=1;i<=k;i++){
        for(int c : s){
            if(i - c >= 0){
                d[i] = min(d[i], d[i-c] + 1);
            }
        }
    }
    if(d[k] == INF) cout<<-1;
    else cout<<d[k];
}