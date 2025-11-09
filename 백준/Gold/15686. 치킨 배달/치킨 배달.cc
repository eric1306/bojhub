// Authored by: prid1306
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
#define y first
#define x second
int n,m;
int ans = 1e9;
using pii = pair<int,int>;
int board[51][51];
vector<pii> ChickenPos;
vector<int> HouseDist;
vector<pii> HousePos;

int main(){
    FASTIO;
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        cin>>board[i][j];
        if(board[i][j] == 2)
            ChickenPos.emplace_back(i,j);
        else if(board[i][j] == 1)
            HousePos.emplace_back(i,j);
    }
    vector<int> v(ChickenPos.size(), 0);
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
        int ret = 0;
        for(auto elem : HouseDist){
            if(elem == 1e9) continue;
            ret += elem;
        }
        ans = min(ret, ans);
    }while(next_permutation(v.begin(), v.end()));
    cout<<ans;
}