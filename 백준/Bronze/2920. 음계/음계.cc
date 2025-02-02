#include <iostream>
#include <string>
using namespace std;

int arr[8];

void compare()
{
    if(arr[0] == 1)
    {
        for(int i=1;i<8;i++){
            if(arr[i]!=i+1){
                cout<<"mixed";
                return;
            }
        }
        cout<<"ascending";
    }
    else if(arr[0] == 8)
    {
        for(int i=1;i<8;i++){
            if(arr[i]!=8-i){
                cout<<"mixed";
                return;
            }
        }
        cout<<"descending";
    }
    else{
        cout<<"mixed";
        return;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<8;i++) cin>>arr[i];
    compare();
}