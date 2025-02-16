//Authored by: prid1306
#include <iostream>
#include <deque>
#include <utility>

using namespace std;
int n;
pair<int,string> p[100001];
pair<int,string> tmp[100001];

void merge(int st, int en){
    int mid = (st+en)/2;
    int lidx = st;
    int ridx = mid;
    for(int i=st;i<en;i++)
    {
        if(lidx == mid) tmp[i] = p[ridx++];
        else if(ridx == en) tmp[i] = p[lidx++];
        else if(p[lidx].first < p[ridx].first) tmp[i] = p[lidx++];
        else if(p[lidx].first == p[ridx].first){
            tmp[i] = p[lidx++];
        }
        else tmp[i] = p[ridx++];
    }
    for(int i=st;i<en;i++) p[i] = tmp[i];
}

void merge_sort(int st, int en)
{
    if(st + 1 == en) return;
    int mid = (st+en)/2;
    merge_sort(st,mid);
    merge_sort(mid,en);
    merge(st,en);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int tmp1;
    string tmp2;
    for(int i=0;i<n;i++){
        cin>>tmp1>>tmp2;
        p[i] = {tmp1,tmp2};
    }
    merge_sort(0,n);
    for(int i=0;i<n;i++){
        cout<<p[i].first<<' '<<p[i].second<<'\n';
    }
}