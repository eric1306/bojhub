#include <iostream>
#include <algorithm>
using namespace std;

int arr[100];
int n,m,i,j;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) arr[i] = i+1;
    while(m--)
    {
        cin>>i>>j;
        swap(arr[i-1],arr[j-1]);
    }
    for(int i=0;i<n;i++)cout<<arr[i]<<' ';
}