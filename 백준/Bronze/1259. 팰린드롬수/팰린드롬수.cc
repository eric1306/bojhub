//Authored by: prid1306
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string n;
    cin >> n;
    while(n!="0")
    {
        bool bflag = true;
        for(int i=0;i<n.size()/2;i++)
        {
            if(n[i] != n[n.size() - i - 1]){
                bflag = false;
            }
        }
        if(bflag) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
        cin>>n;
    }
}