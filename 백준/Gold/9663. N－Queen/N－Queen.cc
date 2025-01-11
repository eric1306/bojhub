#include <iostream>
using namespace std;

int n,ans;
int arr[16][16];
int isused1[30];
int isused2[30];
int isused3[30];

void func(int k){
    if(k == n){
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if(isused1[i] || isused2[i+k] || isused3[k-i+n-1])
            continue;
        isused1[i] = 1;
        isused2[i+k] = 1;
        isused3[k-i+n-1] = 1;
        func(k+1);
        isused1[i] = 0;
        isused2[i+k] = 0;
        isused3[k-i+n-1] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    func(0);
    cout<<ans;
}