//Authored by: prid1306
#include <iostream>
using namespace std;

int n,t,p;
int Tsize[6];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int Tans = 0;
    int Pnum = 0;
    for(int i=0;i<6;i++){
        cin>>Tsize[i];
        Pnum+=Tsize[i];
    }
    cin>>t>>p;
    for(auto c : Tsize)
    {
        Tans += c / t;
        if(c%t!=0) Tans++;
    }
    cout<<Tans<<'\n'<<Pnum/p<<' '<<Pnum%p;
}