//Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<int,int>> t;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)
        return b.second < a.second;
    else   
        return a.first < b.first;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int st_m,st_d,en_m,en_d;
        cin>>st_m>>st_d>>en_m>>en_d;
        int st = st_m * 100 + st_d;
        int en = en_m*100 + en_d;
        t.push_back(make_pair(st,en));
    }
    sort(t.begin(),t.end(),&cmp);
    int start = 301;
    int ans = 0;
    while(start < 1201)
    {
        int nxt_s=start;
        for(int i=0;i<n;i++)
        {
            if(t[i].first <= start && t[i].second > nxt_s){
                nxt_s = t[i].second;
            }
        }
        if(nxt_s == start){
            cout<<0;
            return 0;
        }
        ans++;
        start = nxt_s;
    }
    cout<<ans;
}