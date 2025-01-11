#include <iostream>
using namespace std;

int n;
char arr[3100][6200];
const char STAR = '*';
//행길이: 2n-1 열 길이: n
void rec(int x, int y, int n)
{
    if(n == 3){
        arr[x][y] = STAR;
        arr[x+1][y+1] = STAR;
        arr[x+1][y-1] = STAR;
        for(int i=-2;i<=2;i++) arr[x+2][y+i] =STAR;
        return;
    }
    else{
        rec(x,y,n/2);
        rec(x+n/2,y-n/2,n/2);
        rec(x+n/2,y+n/2,n/2);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) fill(arr[i],arr[i]+2*n,' ');

    rec(0, n-1, n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n*2;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}