// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
vector<int> player;
int score[1'000'001];
bool IsExist[1'000'001];
int _max = -1;
int n;

int main(){
    FASTIO;
    cin>>n;

    player.resize(n);

    for(int i=0;i<n;i++){
        cin>>player[i];
        IsExist[player[i]] = true;
        score[i] = 0;
        if(player[i] > _max) _max = player[i];
    }
    for(auto elem : player) //n개
    {
        int cnt = elem * 2;
        while(cnt <= _max)
        {
            if(IsExist[cnt])
            {
                score[cnt]--;
                score[elem]++;
            }
            cnt += elem;
        }
    }

    for(int i=0;i<n;i++) cout<<score[player[i]]<<' ';
}