// Authored by: prid1306
// BOJ 20166
#include <iostream>
#include <string>
#include <map>
using namespace std;
int n,m,k;
string a[11];
//           좌  하 우 상 좌상 우상 우하 좌하
int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[8] = {0, 1, 0, -1, -1, -1, 1, 1};
map<string, int> um;
/* 
이 풀이가 답이긴 한데, 최적화 하는법
*/
void Solve(int sty, int stx, string s, int cnt){
    if(cnt == 5) return;
    um[s]++;
    for(int i=0;i<8;i++){
        int ny = (sty + dy[i] + n) % n;
        int nx = (stx + dx[i] + m) % m;
        string tmp = (s + a[ny][nx]);
        Solve(ny, nx, tmp, cnt+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    /*
    최대 100개의 칸이 있고, 각 칸에서 신이 좋아하는 문자열이 나올 때 까지 탐색
    8 방향에 대해서 검사 8^4 = 2^15 = 3'267'600 * 일치 시 검사하는데 O(N) 소요
    */
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        string tmp = "";
        tmp += a[i][j];
        Solve(i, j, tmp, 1);
    }
    for(int i=0;i<k;i++){
        string s;cin>>s;
        cout<<um[s]<<'\n';
    }
}