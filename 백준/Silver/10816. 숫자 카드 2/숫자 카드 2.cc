// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
//수의 범위가 20'000'001 -> arr로 처리하기에는 너무 큰 범위이다.
//char로 자료형은 선언한다고 해도 20'000'001 byte -> 20'000 KB -> 20MB, 되겠는데?

int main(){
    FASTIO;
    int n,m;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    cin>>m;
    for(int i=0;i<m;i++){
        int req; cin>>req;
        auto u = upper_bound(v.begin(), v.end(), req);
        auto l = lower_bound(v.begin(), v.end(), req);
        cout<<(u - l)<<' ';
    }
}