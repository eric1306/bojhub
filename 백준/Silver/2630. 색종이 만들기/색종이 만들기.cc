#include <iostream>
using namespace std;

int arr[130][130];
int ans[2];
//arr[0] == while
//arr[1] == blue
int n;

bool checkrange(int x, int y, int s){
    int num = arr[x][y];
    for(int i=x; i<x+s; i++){
        for(int j=y; j < y+s; j++){
            if(arr[i][j]!=num) return false;
        }
    }
    return true;
}

void rec(int x, int y, int s){
    if(s == 1){
        ans[arr[x][y]]++;
        return;
    }

    if(checkrange(x,y,s)){
        ans[arr[x][y]]++;
        return;
    }
    else{
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                rec(x + i*s/2,y + j*s/2,s/2);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    rec(0,0,n);
    cout<<ans[0]<<'\n'<<ans[1]<<'\n';

}