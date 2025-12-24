// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using ll = long long;
const ll INF = 3e9;
int n;
ll ans = INF;
vector<ll> v;
vector<ll> an(3);
int main(){
    FASTIO;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++) 
    {
        cin>>v[i];
    }
    //일단 정렬? 정렬이 주어지면 가능한게 많아지니까
    sort(v.begin(), v.end());
    for(int i=1;i<n-1;i++)
    {
        int st = 0,en = n-1;
        while(st < i && en > i)
        {   
            ll sum = v[st] + v[en] + v[i];
            if(abs(sum) <= ans)
            {
                ans = abs(sum);
                an[0] = v[st];an[1] = v[en];an[2] = v[i];
            }
            if(sum > 0) en--;
            else st++;
        }
    }
    sort(an.begin(), an.end());
    for(auto elem : an) cout<<elem<<' ';
}