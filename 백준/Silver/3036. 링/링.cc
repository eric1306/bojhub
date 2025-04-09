//Authored by: prid1306
#include <iostream>
using namespace std;
int n;
int arr[103];
int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a%b);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=1;i<n;i++){
        int gcd = GCD(arr[0], arr[i]);
        cout<<arr[0] / gcd << "/"<<arr[i]/gcd<<'\n';
    }
}