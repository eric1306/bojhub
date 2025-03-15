//Authored by: prid1306
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int a[500001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int input;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    cin>>m;
    while(m--)
    {
        cin>>input;
        cout<<binary_search(a,a+n,input)<<' ';
    }
}