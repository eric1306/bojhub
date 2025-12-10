// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
/*
n명의 사람 존재. 10만 이하.
각 사람들이 붙어서, 나눠서 0이 나오면 나눈 숫자를 가진 사람이 승리.
게임이 종료된 이후 모든 플레이어의 점수 구하기.
숫자는 100만 이하
가장 쉬운 방법: 최대 10만명을 1명씩 붙어가면서 경쟁시키기.
근데 이렇게 하면 O(N^2)으로 시간복잡도 초과.
그렇다면, 시간복잡도를 줄여야 할 필요가 생김. -> O(logN)시간복잡도가 필요.
1. 본인보다 큰 수와 붙는다면? 최소 무승부. 왜냐하면 상대방 숫자로 나눴을 때 0이 될리가 없음.
본인을 제외한 다른 모든 플레이어와 정확히 한 번씩 결투를 하고 나면 게임이 종료?
*/
vector<int> player;
int score[1'000'001];
vector<pair<int,int>> board; //player value, idx
int n;
bool IsExist[1'000'001];
int _max = -1;

bool cmp(const pair<int,int>& a, const pair<int,int>& b)
{
    if(a.first < b.first) 
        return true;
    return false;
}
int main(){
    FASTIO;
    cin>>n;

    player.resize(n);

    for(int i=0;i<n;i++){
        cin>>player[i];
        IsExist[player[i]] = true;
        score[i] = 0;
        if(player[i] > _max) _max = player[i];
        board.emplace_back(player[i], i);
    }
    //sort(board.begin(), board.end(), cmp);
    for(auto elem : board) //n개
    {
        int cnt = elem.first * 2;
        while(cnt <= _max)
        {
            if(IsExist[cnt])
            {
                score[cnt]--;
                score[elem.first]++;
            }
            cnt += elem.first;
        }
    }

    for(int i=0;i<n;i++) cout<<score[player[i]]<<' ';
}