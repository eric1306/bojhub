#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tmp,ans=0;
    for(int i=0;i<5;i++){
        cin>>tmp;
        ans+=tmp*tmp;
    }
    cout<<ans%10;
}