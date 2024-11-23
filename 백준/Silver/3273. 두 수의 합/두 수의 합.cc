#include <bits/stdc++.h>
using namespace std;
int arr[100001];
bool _visit[1000001]={false,};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x,ans = 0;
    cin>>n;
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
        _visit[arr[i]] = true;
    }
    cin>>x;
    /*1'000'000 * 100'000*/
    for(int i=0;i<n;i++)
    {
        /*if visit this number*/
        if((x-arr[i] <=1000000) && (x-arr[i] > 0) && _visit[arr[i]] && _visit[x-arr[i]])
        {
            ans++;
        }
    }
    cout<<ans/2<<'\n';

}