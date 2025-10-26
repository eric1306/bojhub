// Authored by: prid1306
#include <iostream>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
#define x first
#define y second

int n;
int a[1'000'001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int main(){
    FASTIO;
    //그니까, N개의 수 중에서 가장 작은 애부터 0씩 매기면서 이동하라는거네?
    //정렬X: n이 100만이라 nlogn에 막힘
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        pq.push({a[i], i});
    }
    int cnt = -1;
    int lastNumber = 0;
    while(!pq.empty())
    {
        auto p = pq.top();
        if(lastNumber!=p.x)
        {
            a[p.y] = ++cnt;
            lastNumber = p.x;
        }else
        {
            a[p.y] = cnt;
        }
        pq.pop();
    }
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
}