// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;

int arr[8001]; //최빈값 체크용도의 배열

int getAvg(const vector<int>& v)
{
    int ret = 0;
    for(auto c : v)
    {
        ret += c;
    }
    float size = v.size();
    return round(ret / size);
}

int main(){
    FASTIO;
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        arr[v[i] + 4000]++;
    }
    //산술평균
    cout<<getAvg(v)<<'\n';

    //중앙값
    sort(v.begin(),v.end());
    int idx = (n-1)/2; //n이 무조건 홀수이기 때문에 보장 가능
    cout<<v[idx]<<'\n';
    
    //최빈값
    int max = -1;
    vector<int> cache;
    for(int i=0;i<=8000;i++)
    {
        if(arr[i] > max){
            max = arr[i];
            cache.clear();
            cache.push_back(i-4000);
        }
        else if(arr[i] == max){
            cache.push_back(i - 4000);
        }
    }
    sort(cache.begin(), cache.end());
    if(cache.size() < 2) cout<<cache[0]<<'\n';
    else cout<<cache[1]<<'\n';

    //범위
    cout<<v[n-1] - v[0];

}