//Authored by: prid1306
#include <iostream>
using namespace std;
int n;
pair<int,int> p[100001];
pair<int,int> tmp[100001];

void merge_x(int st,int en){
    int mid = (st+en)/2;
    int lidx = st;
    int ridx = mid;
    for(int i = st;i<en;i++){
        if(lidx == mid) tmp[i] = p[ridx++];
        else if(ridx == en) tmp[i] = p[lidx++];
        else if(p[lidx].first <= p[ridx].first) tmp[i] = p[lidx++];
        else tmp[i] = p[ridx++];
    }
    for(int i=st;i<en;i++) p[i] = tmp[i];
}

void merge_sort_x(int st,int en){
    if(st+1 == en) return;
    int mid = (st+en)/2;
    merge_sort_x(st,mid);
    merge_sort_x(mid,en);
    merge_x(st,en);
}


void merge_y(int st,int en){
    int mid = (st+en)/2;
    int lidx = st;
    int ridx = mid;
    for(int i = st;i<en;i++){
        if(lidx == mid) tmp[i] = p[ridx++];
        else if(ridx == en) tmp[i] = p[lidx++];
        else if(p[lidx].second <= p[ridx].second) tmp[i] = p[lidx++];
        else tmp[i] = p[ridx++];
    }
    for(int i=st;i<en;i++) p[i] = tmp[i];
}

void merge_sort_y(int st,int en){
    if(st+1 == en) return;
    int mid = (st+en)/2;
    merge_sort_y(st,mid);
    merge_sort_y(mid,en);
    merge_y(st,en);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int f,s;
    for(int i=0;i<n;i++) 
    {
        cin>>f>>s;
        p[i] = {f,s};
    }
    //y에 대한 merge sort 후 x merge sort 진행.
    //y 선정렬 하면 stable이 보장됨
    merge_sort_y(0,n);
    merge_sort_x(0,n);
    for(int i=0;i<n;i++){
        cout<<p[i].first<<' '<<p[i].second<<'\n';
    }
}