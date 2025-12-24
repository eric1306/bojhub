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
//-12 -6 -4 4 5 6 12
int CustomBound(int value, int f, int s) //return idx;
{
    int ret = -1;
    int st = 0,en = n-1;
    while(st <= en)
    {
        int mid = (st + en)/2;
        ll sum = value + v[mid];
        if(abs(sum) <= ans && mid != f && mid != s)
        {
            ans = abs(sum);
            ret = mid;
        }
        if(sum > 0) en = mid - 1;
        else st = mid + 1;
    }
    return ret;
}
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
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
    {
        int idx = CustomBound(v[i] + v[j], i, j);
        if(idx != -1)
        {
            an[0] = v[i];an[1] = v[j];an[2] = v[idx];
        }
    }
    sort(an.begin(), an.end());
    for(auto elem : an) cout<<elem<<' ';
}