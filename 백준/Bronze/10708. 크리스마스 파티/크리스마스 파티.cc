// Authored by: prid1306
#include <iostream>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,m;
int main(){
    FASTIO;
    cin>>n;
    vector<int> score(n, 0); //모든 플레이어 점수 보관
    vector<int> input(n); //이번 턴에 플레이어들이 입력한 숫자 보관
    cin>>m;
    vector<int> all_target(m);
    for(int i=0;i<m;i++){cin>>all_target[i];} //i+1번째 턴의 게임에 타겟이 되는 번호 입력받기
    for(int i=0;i<m;i++)
    {
        int target = all_target[i]; //타겟 번호
        for(int i=0;i<n;i++) { cin>>input[i];} //플레이어들이 입력한 숫자 보관
        int x = 0; //타겟이 얻을 추가 점수
        for(int i=0;i<n;i++)
        {
            //만약 본인이 타겟이라면?
            if(i == target - 1) score[i]++;
            //본인이 타겟이 아닌데 타겟이 누군지 예측했다면?
            else
            {
                if(input[i] == target) score[i]++;
                else x++;
            }
        }
        score[target-1]+=x; //타겟의 추가점수 얻기
    }
    for(int elem : score) cout<<elem<<'\n';
}