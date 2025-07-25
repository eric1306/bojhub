// Authored by: prid1306
// BOJ 12865
#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second

using namespace std;
vector<pair<int,int>> vec;
int d[101][100001]; //d[i][j]: i번째 물건까지 봤을 때, 무게가 j일 때의 최대 가치
int n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int w,v;cin>>w>>v;
        vec.emplace_back(w,v);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        d[i][vec[i].X] = vec[i].Y;
    }
    
    for(int i=0;i<vec.size();i++){
        for(int j=1;j<=k;j++){
            if(i - 1 >= 0)
                d[i][j] = d[i-1][j];
            if(j - vec[i].X >= 0)
                if(i - 1 >=0)
                    d[i][j] = max(d[i][j], d[i-1][j - vec[i].X] + vec[i].Y);
                else
                    d[i][j] = vec[i].Y;
            
        }
    }
    cout<<d[n-1][k];
    
}