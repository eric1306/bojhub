// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
vector<int> a;
int size_a;
int main(){
    FASTIO;
    cin>>size_a;
    a.resize(size_a);
    for(int i=0;i<size_a;i++)
    {
        cin>>a[i];
    }

    //가장 긴 증가하는 부분 수열의 길이
    vector<int> lis;
    for(int i=0;i<size_a;i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if(it == lis.end()) lis.push_back(a[i]);
        else
        {
            *it = a[i];
        }
    }
    cout<<lis.size();
}