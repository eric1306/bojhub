#include <iostream>
using namespace std;

int n,ans;
int arr[16][16];

bool IsSpot(int x, int y){
    for(int i=0;i<n;i++){
        if(i == x) continue;

        if(arr[i][y]) 
            return false;
    }
    int xPos = x;
    int yPos = y;
    while(--xPos >= 0 && --yPos >= 0){
        if(arr[xPos][yPos]) return false;
    }
    xPos = x;
    yPos = y;
    while(--xPos >= 0 && ++yPos < n){
        if(arr[xPos][yPos]) return false;
    }
    xPos = x;
    yPos = y;
    while(++xPos < n && --yPos >= 0){
        if(arr[xPos][yPos]) return false;
    }
    xPos = x;
    yPos = y;
    while(++xPos < n && ++yPos < n){
        if(arr[xPos][yPos]) return false;
    }

    return true;
}

void func(int k){
    if(k == n){
        ans++;
        return;
    }
    
    for(int j=0;j<n;j++){
        if(!arr[k][j] && IsSpot(k,j))
        {
            //cout<<i<<j<<' '<<k+1<<'\n';
            arr[k][j] = 1;
            func(k+1);
            arr[k][j] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    func(0);
    cout<<ans;
}