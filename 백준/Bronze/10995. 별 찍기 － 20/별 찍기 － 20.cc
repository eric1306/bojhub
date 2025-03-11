//Authored by: prid1306
#include <iostream>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n*2;j++)
        {
            if((j+i)%2 == 0) cout<<"*";
            else cout<<" ";
        }
        cout<<"\n";
    }
}