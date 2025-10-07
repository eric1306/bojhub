// Authored by: prid1306
#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main(){
    FASTIO;
    int t;cin>>t;
    while(t--)
    {
        int n,m;
        queue<pair<int,int>> q;
        cin>>n>>m;
        vector<int> v(n); //각 idx의 우선순위를 보관할 배열
        for(int i=0;i<n;i++){
            int input;cin>>input;
            q.push({i, input});
            v[i] = input;
        }
        int targetidx = m; int targetvalue = v[m]; //타겟 idx
        sort(v.begin(),v.end(),greater<int>());
        int idx = 0; //현재 몇번째 우선순위가 가장 높은지 체크
        int cnt = 1;
        while(!q.empty()){
            if(q.front().Y == v[idx]) //현재 큐의 top 우선순위가 v[idx]와 같다면
            {
                //걔 빼되, 현재 idx하고 같은지 체크
                if(q.front().X == targetidx){
                    break;
                }
                //큐에서 해당 우선순위 빼고, 다음 우선순위 ++
                q.pop();
                idx++;
                cnt++;
            }
            else{ //다르다면? (아마 낮을 것임)
                //뒤로 보내기
                auto p = q.front();
                q.push(p);
                q.pop();
            }
        }
        cout<<cnt<<'\n';
    }
}