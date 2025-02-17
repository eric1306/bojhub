//Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
vector<string> v;
vector<string> tmp;
int n;
bool cmp(string a, string b){
    for(int i=0;i<a.size() < b.size() ? a.size() : b.size();i++){
        if(a[i] == b[i]) continue;
        return a[i] < b[i];
    }
    return a.size() < b.size();
}

void merge(int st, int en){
    int mid = (st+en)/2;
    int lidx = st;
    int ridx = mid;
    tmp.resize(en);
    for(int i=st;i<en;i++){
        if(lidx == mid) {
            tmp[i] = v[ridx++];
            continue;
        }
        if(ridx == en) {
            tmp[i] = v[lidx++];
            continue;
        }
        if(v[lidx].size() <= v[ridx].size()) tmp[i] = v[lidx++];
        else tmp[i] = v[ridx++];
    }
    for(int i=st;i<en;i++) v[i] = tmp[i];
}

void merge_sort(int st, int en){
    if(st+1 == en) return;
    int mid = (st+en)/2;
    merge_sort(st,mid);
    merge_sort(mid,en);
    merge(st,en);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string input;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    n = v.size(); // unique 이후 크기 조정
    
    merge_sort(0,n);
    
    if(n > 0) {
        cout<<v[0]<<'\n';
        for(int i=1;i<n;i++){
            if(v[i-1] != v[i]){
                cout<<v[i]<<'\n';
            }
        }
    }
}