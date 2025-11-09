// Authored by: prid1306
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
#define y first
#define x second
int n,m,chickenCount, HouseCnt;
int ans = 1e9;
using pii = pair<int,int>;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int board[51][51];
pii ChickenPos[14];
int dist[51][51];
vector<pii> HousePos;
//최대 m개니까, m개보다 작은 치킨집을 골랐을 때 치킨거리가 작게 되는 경우? -> 없지 않을까? 모르겠다.

void UpdateDistFromChickenPos(int idx)
{
    for(auto house : HousePos)
    {
        int value = abs(house.y - ChickenPos[idx].y) + abs(house.x - ChickenPos[idx].x);
        dist[house.y][house.x] = min(dist[house.y][house.x], value);
    }
}

int GetAllDist()
{
    int ret = 0;
    for(int i=0;i<51;i++) for(int j=0;j<51;j++){
        if(dist[i][j] == 1e9) continue;
        ret += dist[i][j];
        //cout<<"dist["<<i<<"]["<<j<<"]: "<<dist[i][j]<<'\n';
    }
    // cout<<"ret: "<<ret<<'\n';
    // cout<<"-------------\n";
    return ret;
}

int main(){
    FASTIO;
    cin>>n>>m;
    //각 board 판의 info, 치킨집 개수와 position을 캐싱
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        cin>>board[i][j];
        if(board[i][j] == 2)
            ChickenPos[chickenCount++] = make_pair(i, j);
        else if(board[i][j] == 1)
            HousePos.emplace_back(i,j);
    }
    vector<int> v(chickenCount, 0);
    int size = static_cast<int>(v.size());
    for(int i= size - 1; i>size - 1 - m; i--){
        v[i] = 1;
    }    
    do{
        // for(auto elem : v) 
        //     cout<<elem<<' ';
        // cout<<'\n';
        for(int i=0;i<51;i++){
            fill(dist[i], dist[i] + 51, 1e9);
        }
        //각 치킨집에서 집 번호까지 len 구하기
        for(int i=0;i<v.size(); ++i)
        {
            if(v[i] == 1)
            {
                //cout<<"checked pos: ["<<i<<"] "<<ChickenPos[i].y<<' '<<ChickenPos[i].x<<'\n';
                //그 치킨집이 체크해야할 치킨집이라면, 해당 치킨집으로부터 모든 집까지의 거리 구하기
                UpdateDistFromChickenPos(i);
            }
        }
        //구해진 모든 집의 최소값과 ans를 비교해서 갱신
        int tmp = GetAllDist();
        ans = min(tmp, ans);
        //cout<<"*********************\n";
    }while(next_permutation(v.begin(), v.end()));
    cout<<ans;
}