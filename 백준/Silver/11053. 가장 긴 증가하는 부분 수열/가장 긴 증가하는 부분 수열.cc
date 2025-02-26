//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1001];
int d[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    fill(d,d+1001,1);
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(arr[i] > arr[j]){
                d[i] = max(d[i],d[j] + 1);
            }
        }
    }
    cout<<*max_element(d+1,d+1001);
}