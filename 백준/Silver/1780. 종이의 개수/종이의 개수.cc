#include <iostream>
using namespace std;

const int MAX = 2187;
int n;
int arr[MAX+1][MAX+1];
int ans[3]={0,0,0};
/*-1,0,1*/
bool checkAll(int px, int py, int nx, int ny){
    int num = arr[px][py];
    for(int i = px; i<=nx;i++){
        for(int j=py;j<=ny;j++){
            if(arr[i][j]!=num){
                return false;
            }
        }
    }
    return true;
}
void rec(int px,int py, int nx, int ny){
    if(px > nx || py > ny) return;

    if(px == nx && py == ny){
        if(arr[px][py] == 0) ans[1]++;
        else if(arr[px][py] == 1) ans[2]++;
        else ans[0]++;
        return;
    }
    if(!checkAll(px,py,nx,ny)){
        int dist = (nx-px+1)/3; //
        rec(px, py, px + dist-1, py + dist-1);
        rec(px+dist, py, px + dist*2 - 1, py + dist-1);
        rec(px+dist*2, py, nx, py + dist-1);

        rec(px, py+dist, px + dist-1, py + dist*2-1);
        rec(px+dist, py+dist, px + dist*2 - 1, py + dist*2-1);
        rec(px+dist*2, py+dist, nx, py + dist*2-1);

        rec(px, py+dist*2, px + dist-1, ny);
        rec(px+dist, py+dist*2, px + dist*2 - 1, ny);
        rec(px+dist*2, py+dist*2, nx, ny);
    }else{
        ans[arr[px][py]+1]++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    rec(1,1,n,n);
    for(int v: ans) cout<<v<<'\n';
}