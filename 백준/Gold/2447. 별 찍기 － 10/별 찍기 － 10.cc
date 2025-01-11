#include <iostream>
using namespace std;

char arr[2200][2200];
int n;
const char STAR = '*';
void fillspace(int x, int y, int z)
{
    for(int i=x;i<x+z;i++){
        for(int j = y;j<y+z;j++){
            arr[i][j] = ' ';
        }
    }
}
void rec(int x, int y, int s){
    if(s == 3)
    {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==1 && j == 1) arr[x+i][y+j] = ' ';
                else arr[x+i][y+j] = STAR;
            }
        }
        return;
    }
    else{
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==1 && j == 1){
                    fillspace(x+s/3,y+s/3,s/3);
                }
                else rec(x+i*s/3,y+j*s/3,s/3);
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    rec(0,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}