// Authored by: prid1306
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int t,n,m;
unsigned long long ans;
int a[1001];
int b[1001];
vector<int> subA;
vector<int> subB;
unordered_map<int,int> dt;

int main(){
    FASTIO;
    cin>>t>>n;
    int input;
    a[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>input;
        a[i] = a[i-1] + input;
    }
    cin>>m;
    b[0] = 0;
    for(int i=1;i<=m;i++)
    {
        cin>>input;
        b[i] = b[i-1] + input;
    }
    //부 배열 구하기
    for(int i=0;i<=n;i++) for(int j=i+1;j<=n;j++){
        subA.push_back(a[j] - a[i]);
    }
    for(int i=0;i<=m;i++) for(int j=i+1;j<=m;j++){
        subB.push_back(b[j] - b[i]);
    }
    if(subA.size() < subB.size())
    {
        std::swap(subA, subB);
    }
    std::sort(subA.begin(),subA.end());
    for(int i=0;i<subB.size();i++){
        int target = t - subB[i];
        ans += (upper_bound(subA.begin(), subA.end(), target) - lower_bound(subA.begin(),subA.end(),target));
    }
    cout<<ans;
}