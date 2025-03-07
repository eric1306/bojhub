//Authored by: prid1306
#include <iostream>
using namespace std;
int n;
#define SG 1
#define CY 0

//d[i][j] : 돌이 n개일때 j가 시작할 때 누가 이기는가 0: 상근 / 1: 창영
int d[1001][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int tmp = n%4;
    if(tmp == 1 || tmp == 3) cout<<"SK";
    else cout<<"CY";
}