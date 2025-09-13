// Authored by: prid1306
// BOJ 1520
//(0, 0) -> (n-1, m-1)
#include <iostream>
//M과 N이 500 이하, 높이 10000 이하이기 때문에 1000 * 10000 = 10'000'000 -> int OK
using namespace std;
int a[501][501]; //a[i][j]: (i,j) 칸의 높이
int d[501][501]; //d[i][j]: (i,j)칸 까지 항상 내리막길로 이동하는 경로의 개수
/*
21% 시간 초과 발생
단순 visit 체크 -> 안되는 경로를 더하는 참사 발생
*/
int n,m; //n -> 행(row), m -> 열(column)
//좌, 하, 우, 상(시계 방향)
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int DFS(int y, int x){ //(0, 0)에서 (y, x) 까지 가는 경로의 개수를 계산하는 함수
    if(d[y][x] > 0){
        //cout<<"break because d[y][x] is "<<d[y][x]<<'\n';
        return d[y][x]; //최초 방문이 아닌데, 경로가 없는 경우 스킵
    }
    if(d[y][x] == -1) d[y][x] = 0; //최초 방문 처리
    
    //cout<<"this DFS Function Check (0, 0) -> "<<y<<", "<<x<<'\n';
    if(y == 0 && x == 0){ //(0, 0)에 도달했다 -> 경로를 하나 찾았다
        //cout<<"arrive in (0, 0)!"<<'\n';
        return d[y][x];
    }
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue; //범위 초과 예외처리
        //base condition을 어떻게 정할것인가?
        if(a[y][x] < a[ny][nx] && d[ny][nx]!=0){
            d[y][x] += DFS(ny, nx);
        }
    }
    //cout<<"d["<<y<<"]["<<x<<"] return "<<d[y][x]<<'\n';
    return d[y][x];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<501;i++){
        fill(d[i], d[i]+501, -1);
    }
    cin>>n>>m;
    int H = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){cin>>a[i][j];}
    d[0][0] = 1;
    H = DFS(n-1, m-1);
    cout<<H<<'\n';
}