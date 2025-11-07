// Authored by: prid1306
#include <iostream>
#include <algorithm>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int dmax[2][3]; // d[i][j]: i행 j열까지 도달하는데 최댓값
int dmin[2][3]; // d[i][j]: i행 j열까지 도달하는데 최소값
int first, second, third;
int n;
using pii = pair<int,int>;
int main(){
    FASTIO;
    cin>>n;
    cin>>first>>second>>third;
    dmin[0][0] = dmax[0][0] = first;
    dmin[0][1] = dmax[0][1] = second;
    dmin[0][2] = dmax[0][2] = third;
    for(int i=1;i<n;i++){
        cin>>first>>second>>third;
        dmax[1][0] = max(dmax[0][0], dmax[0][1]) + first;
        dmax[1][1] = max(dmax[0][0], max(dmax[0][1], dmax[0][2])) + second;
        dmax[1][2] = max(dmax[0][1], dmax[0][2]) + third;
        dmax[0][0] = dmax[1][0]; dmax[0][1] = dmax[1][1]; dmax[0][2] = dmax[1][2];

        dmin[1][0] = min(dmin[0][0], dmin[0][1]) +first;
        dmin[1][1] = min(dmin[0][0], min(dmin[0][1], dmin[0][2])) + second;
        dmin[1][2] = min(dmin[0][1], dmin[0][2]) + third;
        dmin[0][0] = dmin[1][0]; dmin[0][1] = dmin[1][1]; dmin[0][2] = dmin[1][2];
    }
    cout<<max(dmax[0][0], max(dmax[0][1], dmax[0][2]));
    cout<<' '<<min(dmin[0][0], min(dmin[0][1], dmin[0][2]));
}