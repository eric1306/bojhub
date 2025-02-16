//Authored by: prid1306
#include <iostream>
using namespace std;
int n;
int arr[2000001]; /*`1'000'000~1'000'000 까지의 범위*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        arr[tmp+1'000'000]++;
    }
    for(int i=0;i<2'000'001;i++){
        while(arr[i]--){
            cout<<i-1'000'000<<'\n';
        }
    }
}