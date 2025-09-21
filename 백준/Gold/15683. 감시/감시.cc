// Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,m,cctvNum, ans;
int board[10][10];
int cacheBoard[10][10];
vector<pair<int,int>> cctv;
vector<int> cctvType;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int CheckBoard(){
    int ret = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(board[i][j] == 0){
            ret++;
        }
    }
    return ret;
}

void InitializeBoard(){
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        board[i][j] = cacheBoard[i][j];
    }
}

void PrintBoard(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
}

bool OOR(int x, int y){ //해당 idx가 범위를 벗어나면 true 반환
    return (x < 0 || x >= n || y < 0 || y >= m);
}
void arrow(pair<int,int> p, int dir){
    int x = p.first,y = p.second;
    dir%=4;
    while(true){
        x += dx[dir];y +=dy[dir];
        if(OOR(x, y) || board[x][y] == 6){
            break;
        }
        board[x][y] = -1;
    }
}

void check(int dir){
    vector<int> cctvdir;
    int cnt = 0;
    while(dir > 0){
        cctvdir.push_back(dir%4);
        dir /= 4;
    }
    int amount = cctvNum - cctvdir.size();
    if(cctvdir.size() < cctvNum){
        while(amount--){
            cctvdir.push_back(0);
        }
    }
    for(int i=0;i<cctvNum;i++){
        if(cctvType[i] == 1){
            arrow(cctv[i], cctvdir[i]);
        }else if(cctvType[i] == 2){
            arrow(cctv[i], cctvdir[i]);
            arrow(cctv[i], cctvdir[i]+2);
        }else if(cctvType[i] == 3){
            arrow(cctv[i], cctvdir[i]);
            arrow(cctv[i], cctvdir[i]+3);
        }else if(cctvType[i] == 4){
            arrow(cctv[i], cctvdir[i]);
            arrow(cctv[i], cctvdir[i]+2);
            arrow(cctv[i], cctvdir[i]+3);
        }else{
            arrow(cctv[i], cctvdir[i]);
            arrow(cctv[i], cctvdir[i]+1);
            arrow(cctv[i], cctvdir[i]+2);
            arrow(cctv[i], cctvdir[i]+3);
        }
    }
    int cur = CheckBoard();
    ans = min(cur, ans);
}

int main(){
    FASTIO;
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        cin>>board[i][j];
        if(board[i][j]!=0 && board[i][j]!=6){ //CCTV 위치 체크해두기
            cctv.emplace_back(i, j);
            cctvType.push_back(board[i][j]);
        }
        cacheBoard[i][j] = board[i][j];
    }
    ans = n * m;
    cctvNum = cctv.size();
    //각 CCTV 개수 별로 4개의 방향을 꺽는 케이스 분석
    //2^(2*n) - 1
    for(int i=0;i<(1<<(cctvNum*2));i++){
        check(i);
        //PrintBoard();
        InitializeBoard();
    }
    cout<<ans;
}