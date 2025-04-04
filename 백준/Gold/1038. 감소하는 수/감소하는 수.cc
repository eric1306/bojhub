#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
//0~9876543210(이 한계다)
vector<bool> v(10, 0);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int cnt = 0;
    for(int i = 1; i <= 10; i++) {
        v[10 - i] = 1;
        do {
            if(cnt != n) {
                cnt++;
                continue;
            }
            for(int i = 0; i < 10; i++)
                if(v[i]) cout << 9 - i;
            return 0;
        } while(next_permutation(v.begin(), v.end()));
    }
    cout << -1;
}