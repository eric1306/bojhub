// Authored by: prid1306
// BOJ 25515
/*
tree구조가 주어지고, root node에서 이웃한 노드들을 어떻게 방문해야 정수합의 최댓값이 되는가?
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//subtree의 합이 0 초과일 때만 사용, 아니면 무시
using ll = long long;
vector<int> v[100'001];
int value[100'001];
const ll ZERO = 0;
ll DFS(ll cur, ll prev) //cur의 subtree에서 거치는 노드들의 합이 최대가 되도록 
{
    //cout<<"current node: "<<cur<<" prev node: "<<prev<<'\n';
    ll ret = value[cur];
    for(int elem : v[cur]){
        if(elem == prev) continue;
        //cout<<"subtree elem: "<<elem<<'\n';
        ret += max(DFS(elem, cur), 0LL);
        //cout<<"ret: "<<ret<<'\n';
    }
    //cout<<"will return ret: "<<ret<<'\n';
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int parent, child;cin>>parent>>child;
        v[parent].push_back(child);v[child].push_back(parent);
    }
    for(int i=0;i<n;i++){
        int val;cin>>val;
        value[i] = val;
    }
    cout<<DFS(0, -1);
}