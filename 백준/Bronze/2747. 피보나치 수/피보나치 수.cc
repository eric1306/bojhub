#include <iostream>
using namespace std;

int n;
int fibonacci(int cnt,int x,int y){
    if(cnt == n) return x;
    return fibonacci(++cnt,y, x+y);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cout<<fibonacci(1,1,1);
}