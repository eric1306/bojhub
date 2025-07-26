// Authored by: prid1306
// BOJ 2961
#include <iostream>
#include <vector>
#define x first
#define y second
using namespace std;
int n;
int _min = 1'000'000'000;
vector<pair<int,int>> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int s,b;cin>>s>>b;
        v.emplace_back(s, b);
    }
    for(int i=1;i<(1<<n);i++){
        int tmp = 1;
        int sum_s = 1, sum_b = 0;
        for(int j=0;j<n;j++){
            if(i & (tmp<<j)){
                sum_s*=v[j].x;
                sum_b+=v[j].y;
            }
        }
        int ret = sum_s >= sum_b ? sum_s - sum_b : sum_b - sum_s;
        if(_min > ret) _min = ret;
    }
    cout<<_min;
} 