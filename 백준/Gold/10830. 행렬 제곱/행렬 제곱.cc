// Authored by: prid1306
#include <iostream>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n;
using ull = unsigned long long;
using vvi = vector<vector<int>>;
ull b;
vvi matrix;
vvi originmatrix;
vvi doublematrix;


vvi multimatrix(vvi mata, vvi matb)
{
    vvi ret(n, vector<int>(n, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ret[i][j] = (ret[i][j] + mata[i][k] * matb[k][j])%1000;
            }
        }
    }
    return ret;
}

int main(){
    FASTIO;
    cin>>n>>b;
    matrix.resize(n); originmatrix.resize(n);
    for(int i=0;i<n;i++) {
        matrix[i].resize(n);
        originmatrix[i].resize(n);
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
            originmatrix[i][j] = matrix[i][j];
        }
    }

    vvi ans(n, vector<int>(n, 0));
    for(int i=0;i<n;i++) 
        ans[i][i] = 1;
    
    while(b)
    {
        if(b%2 != 0)
            ans = multimatrix(ans, matrix);
        matrix = multimatrix(matrix, matrix);
        b /=2;
    }

    for(auto vector : ans){
        for(auto elem : vector){
            cout<<elem%1000<<' ';
        }
        cout<<'\n';
    }
}