// Authored by: prid1306
#include <iostream>
#include <vector>
#include <queue>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,m, TrueKnowNumber;
bool isKnowTrue[51];
int ans = 0;
vector<int> knowtrueperson;
int main(){
    FASTIO;
    cin>>n>>m;
    cin>>TrueKnowNumber;
    for(int i=0;i<TrueKnowNumber;i++){
        int input;cin>>input;
        isKnowTrue[input] = true;
        knowtrueperson.push_back(input);
    }
    // 그래프를 통해 긱 사람들이 진실을 아는지 체크
    vector<int> party[51]; //각 파티에 있는 사람들을 나타내는 배열
    vector<int> adj[51];
    for(int i=0;i<m;i++){
        int num;cin>>num;
        vector<int> cachePerson;
        for(int j=0;j<num;j++){
            int person; cin>>person;
            for(int per : cachePerson)
            {
                adj[per].push_back(person);
                adj[person].push_back(per);
            }
            cachePerson.push_back(person);
            party[i].push_back(person);
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=0;j<adj[i].size();j++)
    //     {
    //         cout<<"adj["<<i<<"]["<<j<<"] is: "<<adj[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    queue<int> q;
    for(auto c : knowtrueperson)
    {
        q.push(c);
    }
    while(!q.empty())
    {
        auto p = q.front(); q.pop();
        //cout<<p<<'\n';
        for(int nxt : adj[p])
        {
            if(isKnowTrue[nxt]) continue;
            isKnowTrue[nxt] = true;
            q.push(nxt);
            //cout<<nxt<<'\n';
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<isKnowTrue[i]<<' ';
    // }
    // cout<<'\n';


    //이 방식의 문제점-> 나중에 갱신되면, 추가적으로 갱신되는 사람들을 알 수 없음.
    // 각 파티마다 for문 돌려서 진실을 모르는 사람만 있다면 ++ 아니라면 break;
    for(int i=0;i<m;i++){
        bool bNoOneKnowTrue = true;
        for(int person : party[i])
        {
            if(isKnowTrue[person])
            {
                bNoOneKnowTrue = false;
                break;
            }
        }
        if(bNoOneKnowTrue)
        {
            ans++;
        }
    }
    cout<<ans<<'\n';
}