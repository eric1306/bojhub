// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int main(){
    FASTIO;
    int n1, n2;
    cin>>n1>>n2;
    //결국 시계방향 회전 vs 반시계 방향 회전 중에서 어떤 값이 더 작은지 출력하는 문제
    int clock = (n2 - n1 + 360)%360;
    int clockwise = (n1-n2 + 360)%360;
    cout<<(clock > clockwise ? -1 * clockwise : clock);
}