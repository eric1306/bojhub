// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
//수의 범위가 20'000'001 -> arr로 처리하기에는 너무 큰 범위이다.
//unsigned short 자료형은 선언한다고 해도 20'000'001 byte -> 20'000 KB -> 20MB, 되겠는데?
const int AOFFSET = 10'000'000;
int a[20'000'001];
int main(){
    FASTIO;
    int n,m;cin>>n;
    
    for(int i=0;i<n;i++){
        int input;cin>>input;
        a[input + AOFFSET]++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int req; cin>>req;
        cout<<a[req + AOFFSET]<<' ';
    }
}