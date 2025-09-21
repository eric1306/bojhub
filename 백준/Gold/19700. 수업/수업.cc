// Authored by: prid1306
// BOJ 19700
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
/*
k가 1이라면 그룹에서 본인이 가장 키가 큰 사람이어야함.
k가 2라면 그룹에서 본인이 최소 2번째로 키가 큰 사람이어야함.
...
그룹에서 본인이 최소 k번째로 키가 큰 사람이어야함.
vector<pair<int,int>> v로 (키, 최소 등수) 입력 받기
(키 높은순, 키가 같다면 등수가 더 높은 순) 으로 정렬
키순 정렬 -> 다음에 뽑히는 애는 이전에 넣었던 애들보다 무~조건 작은게 보장이 됨.
*/
int main(){
    FASTIO;
    int n;cin>>n;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        cin>>vp[i].first>>vp[i].second;
    }
    sort(vp.begin(), vp.end(), greater<pair<int,int>>()); //키가 큰 순서대로, 키가 같다면 최소 등수가 높은 순서대로 정렬
    //이렇게 처리함으로써, 뒤에서 뽑히는 친구는 앞에 뽑힌 친구들 보다 키가 작다는게 무조~건 보장이 됨.
    multiset<int> ms;
    for(int i=0;i<n;i++){
        auto it = ms.lower_bound(-vp[i].second + 1); //vp[i].second(최소등수) - 1 명의 팀원이 있는 곳 까지 괜찮음. 초과하는 곳 탐색
        if(it == ms.end()){ //조건을 만족하는 팀이 없음. 고로 삽입
            ms.insert(-1); // 새로운 팀 생성, 이 친구는 처음 삽입됐기 때문에 1등.
        }else{
            int value = *it; //해당 팀에 삽입(-1 해주기)
            ms.erase(it);
            ms.insert(value-1);
        }
    }
    cout<<ms.size();
}