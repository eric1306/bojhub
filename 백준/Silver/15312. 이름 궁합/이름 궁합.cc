// Authored by: prid1306
// BOJ 15312
#include <iostream>
#include <string>
using namespace std;
int AlphaBet[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
string A,B;
int arr[4001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B;
    for(int i=0;i<A.size()*2;i++){
        arr[i] = i%2 == 0 ? AlphaBet[A[i/2] - 'A'] : AlphaBet[B[i/2] - 'A'];
    }
    int cnt = A.size()*2;
    while(cnt > 2){
        for(int i=0;i<cnt-1;i++){
            arr[i] = (arr[i] + arr[i+1])%10;
        }
        cnt--;
    }
    cout<<arr[0]<<arr[1];
} 