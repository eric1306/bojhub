//Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
int n;
ll arr[100001];

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n, less<ll>());
    vector<pair<ll,int>> v;
    v.push_back({arr[0],1});
    for(int i=1;i<n;i++){
        if(v.back().first == arr[i]) {
            v.back().second++;
        }
        else{
            v.push_back({arr[i],1});
        }
    }
    int ans = -1;
    ll ansnum = 4611686018427387903;
    for(auto c : v){
        if(c.second > ans){
            ans = c.second;
            ansnum = c.first;
        }else if(c.second == ans && ansnum > c.first) ansnum = c.first;
    }
    cout<<ansnum;
}