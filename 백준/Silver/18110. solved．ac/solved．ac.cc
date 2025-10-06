// Authored by: prid1306
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main(){
    FASTIO;
    int n;cin>>n;
    if(n == 0){
        cout<<0;return 0;
    }
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    //절사평균할 값을 정한다.
    double ans = 0;
    int avg_value = round(n * 0.15);
    for(int i=avg_value; i < n - avg_value;i++){
        ans += v[i];
    }
    cout<<round(ans / (n - avg_value*2));
}