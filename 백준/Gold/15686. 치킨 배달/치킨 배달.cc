// Authored by: prid1306
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
#define y first
#define x second
int n,m,chickenCount;
int ans = 1e9;
using pii = pair<int,int>;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int board[51][51];
pii ChickenPos[14];
vector<int> HouseDist;
vector<pii> HousePos;

int GetAllDist()
{
    int ret = 0;
    for(auto elem : HouseDist){
        if(elem == 1e9) continue;
        ret += elem;
    }
    return ret;
}

int main(){
    FASTIO;
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        cin>>board[i][j];
        if(board[i][j] == 2)
            ChickenPos[chickenCount++] = make_pair(i, j);
        else if(board[i][j] == 1)
            HousePos.emplace_back(i,j);
    }
    vector<int> v(chickenCount, 0);
    HouseDist.resize(HousePos.size(), 1e9);
    int size = static_cast<int>(v.size());
    for(int i= size - 1; i>size - 1 - m; i--){
        v[i] = 1;
    }    
    do{
        fill(HouseDist.begin(), HouseDist.end(), 1e9);
        for(int i=0;i<v.size(); ++i)
        {
            if(v[i] == 1)
            {
                for(int j=0;j<HousePos.size(); j++)
                {
                    int value = abs(HousePos[j].y - ChickenPos[i].y) + abs(HousePos[j].x - ChickenPos[i].x);
                    HouseDist[j] = min(HouseDist[j] , value);
                }
            }
        }
        int tmp = GetAllDist();
        ans = min(tmp, ans);
    }while(next_permutation(v.begin(), v.end()));
    cout<<ans;
}