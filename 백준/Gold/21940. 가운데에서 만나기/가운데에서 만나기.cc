//Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int d[203][203];
int n,m,k;
const int INF = 0x0fffffff;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        fill(d[i],d[i] + 1 + n, INF);
    for(int i=1;i<=m;i++)
    {
        int a,b,t;
        cin>>a>>b>>t;
        d[a][b] = min(d[a][b],t);
    }
    for(int i=1;i<=n;i++) d[i][i] = 0;
    for(int k=1;k<=n;k++) for(int s = 1;s<=n;s++) for(int t = 1; t <= n;t++){
        if(d[s][t] > d[s][k] + d[k][t])
            d[s][t] = d[s][k] + d[k][t];
    }
    cin>>k;
    vector<int> v(k, 0);
    for(int i=0;i<k;i++) 
        cin>>v[i];
    /*
    v원소들의 왕복 거리를 구하면서, 최대값을 구하고, 최대값의 최소를 ans에 갱신
    
    */
    int ans = 0x7fffffff;
    vector<int> vans;
    for(int i=1;i<=n;i++)
    {
        int max = -1;
        for(int j=0;j<k;j++)
        {
            int tmp = (d[v[j]][i] + d[i][v[j]]);
            if(max < tmp) max = tmp;
        }
        if(ans > max){
            vans.clear();
            ans = max;
            vans.push_back(i);
        }
        else if(ans == max) vans.push_back(i);
    }
    sort(vans.begin(),vans.end());
    for(auto c : vans) cout<<c<<' ';

}