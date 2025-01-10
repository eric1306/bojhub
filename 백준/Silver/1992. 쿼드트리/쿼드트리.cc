/*Quard Tree*/
#include <iostream>
#include <string>
using namespace std;

string arr[65];
int n;
int ans[2];

bool check(int x, int y, int s){
    char num = arr[x][y];
    for(int i=x;i<x+s;i++){
        for(int j=y;j<y+s;j++){
            if(arr[i][j]!=num) return false;
        }
    }
    return true;
}

void rec(int x, int y, int s)
{
    if(s == 1)
    {
        cout<<arr[x][y];
        return;
    }
    if(!check(x,y,s))
    {
        cout<<"(";
        for(int i : {0,1})
        {
            for(int j : {0,1})
            {
                rec(x+i*s/2, y+j*s/2,s/2);
            }
        }
        cout<<")";
    }
    else
    {
        cout<<arr[x][y];
        return;
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    
    rec(0,0,n);
}