// Authored by: prid1306
#include <iostream>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
/*
최소 곱셈 연산 횟수를 구하기
[a*b][b*c][c*d][d*e][e*f]
O(n*r*c) //까진 괜찮음
d[i]: i번째 행렬까지의 곱셈 연산 수의 최소값
d[i][j]: 행렬의 i번째원소~j번째 원소 곱셈 연산 수의 최소값?
d[1] = 0;
d[2] = a * b * c; -> 케이스가 1개
d[3] = ABC -> (AB)C A(BC) size(d[i])-1
(d[4] = ABCD -> (((AB)C)D)
5 * 3 
d[i][j]: for(k in i~k) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
5*4 4*3 3*2 2*7
5*4*3 + 3*2*7 -> 5*3*7 ->
5*4*3 + 5*3*2 + 5*2*7
4*3*2 + 5*4*2 + 
*/
int d[501][501];
const int MAX = 1e9;
vector<pair<int,int>> v;
int main(){
    FASTIO;
    int n;
    cin>>n;
    if(n == 1){
        cout<<0; return 0;
    }
    for(int i=0;i<n;i++)
    {
        fill(d[i], d[i] + n, MAX);
    }
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        d[i][i] = 0;//초기값 설정
    }
    for(int i=0;i<n-1;i++)
    {
        d[i][i+1] = v[i].first * v[i].second * v[i+1].second;
    }
    for(int i=2;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            for(int k=j;k<(j + i);k++)
            {   
                d[j][j + i] = min(d[j][j + i], d[j][k] + d[k+1][j + i] + v[j].first * v[k].second  * v[j + i].second);
                //cout<<i<<' '<<k<<' '<<j<<' '<<d[j][k]<<' '<<d[k][j+i]<<'\n';
                //cout<<"d["<<j<<"]["<<j + i<<"]: "<<d[j][j + i]<<'\n';
            }
        }
    }
    cout<<d[0][n-1];
}