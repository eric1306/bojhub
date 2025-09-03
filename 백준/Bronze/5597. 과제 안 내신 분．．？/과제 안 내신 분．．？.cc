// Authored by: prid1306
// BOJ 5597
#include <iostream>
using namespace std;
int student[31];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<28;i++){
        int stdnum;cin>>stdnum;
        student[stdnum] = 1;
    }
    for(int i=1;i<=30;i++){
        if(student[i] == 0) 
            cout<<i<<'\n';
    }
}