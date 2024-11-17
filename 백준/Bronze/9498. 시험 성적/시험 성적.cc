#include <iostream>
using namespace std;
int s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    cout<<(s>=90 ? 'A' : (s>=80 ? 'B' : (s>=70 ? 'C' : (s>=60 ? 'D' : 'F'))));
}