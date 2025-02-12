// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog, dustmddus
// http://boj.kr/f7b9b1367b054a08a753f1096b829b26
#include <bits/stdc++.h>
using namespace std;

int n, l;
int board[102][102];

bool check(vector<int>& line){
    int idx = 0;
    int cnt = 1; // 현재 보고 있는, 높이가 같은 구간의 길이
    while (idx < n - 1) {
        if (abs(line[idx + 1] - line[idx]) > 1) return 0;
        if (line[idx] == line[idx + 1]) {
        cnt++;
        idx++;
        }
        else if (line[idx] < line[idx + 1]) {
        if (cnt < l) return 0;
        cnt = 1;
        idx++;
        }
        else {  
        if (idx + l >= n) return 0;
        for (int i = idx + 1; i < idx + l; i++)
            if (line[i] != line[i + 1]) return 0;
        idx = idx + l;
        cnt = 0;
        }
    }
    return 1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        cin >> board[i][j];

    int ans = 0;


    for (int i = 0; i < n; i++){
        vector<int> line;
        for(int j = 0; j < n; j++) line.push_back(board[i][j]);
        ans += check(line);
    }


    for (int i = 0; i < n; i++){
        vector<int> line;
        for(int j = 0; j < n; j++) line.push_back(board[j][i]);
        ans += check(line);
    }
    cout << ans;
}