// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int a,b,c;
void CheckAngle(const int& a, const int& b, const int& c)
{
    if((a + b + c)!=180 ){
        cout<<"Error"; 
        return;
    }

    if(a == b && b == c && c == a){ //세 각의 크기가 60인 경우
        cout<<"Equilateral";
        return;
    }
    else if(a!=b && b!=c && c!= a){ //같은 각이 없음.
        cout<<"Scalene"; 
        return;
    }else if(a == b || b == c || c == a){
        cout<<"Isosceles"; 
        return;
    }
}
int main(){
    FASTIO;
    cin>>a>>b>>c;
    CheckAngle(a, b, c);
}