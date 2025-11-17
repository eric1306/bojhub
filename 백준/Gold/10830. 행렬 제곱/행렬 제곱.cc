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
    vvi ret(n);
    for(int i=0;i<n;i++){
        ret[i].resize(n);
        for(int j=0;j<n;j++){
            ret[i][j] = 0;
            for(int k=0;k<n;k++){
                ret[i][j] = (ret[i][j] + mata[i][k] * matb[k][j])%1000;
            }
        }
    }
    return ret;
}
vvi DQ(ull st, ull en)
{   
    if(en - st == 1){
        return originmatrix;
    }
    else if(en - st == 2){
        return doublematrix;
    }
    vvi ret;
    if((en - st) % 2 == 0)
    {
        ull mid = (st + en)/2;
        vvi mat = DQ(st, mid);
        ret = multimatrix(mat, mat);
    }else{
        ull mid = (en + st + 1)/2;
        vvi mat =  DQ(st + 1, mid);
        ret = multimatrix(originmatrix, multimatrix(mat, mat));
    }
    return ret;
}

int main(){
    FASTIO;
    cin>>n>>b;

    matrix.resize(n);
    originmatrix.resize(n);
    doublematrix.resize(n);
    for(int i=0;i<n;i++) {
        matrix[i].resize(n);
        originmatrix[i].resize(n);
        doublematrix[i].resize(n);
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
            originmatrix[i][j] = matrix[i][j];
        }
    }

    doublematrix = multimatrix(originmatrix, originmatrix);

    vvi ans = DQ(0, b);
    for(auto vector : ans){
        for(auto elem : vector){
            cout<<elem%1000<<' ';
        }
        cout<<'\n';
    }
}