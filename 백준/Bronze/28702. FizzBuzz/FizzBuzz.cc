// Authored by: prid1306
#include <iostream>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
//문자열의 길이가 8 이하 -> 99'999'999 즉, 1억 이하까지의 값을 .5초 이내에 모두 구할 수 있다면
//가능이지만...상식적으로 말이 안되고
/*
입력 케이스는 4개
Fizz
Buzz
FizzBuzz
그냥 숫자 문자열
*/
int ans;
int main(){
    FASTIO;
    for(int i=0;i<3;i++){
        string s;
        cin>>s;
        if(s == "Fizz" || s == "Buzz" || s == "FizzBuzz" || ans){
            continue;
        }else{
            ans = stoi(s);
            ans = ans + 3 - i;
            if(ans%3 == 0 && ans % 5 == 0){
                cout<<"FizzBuzz";
            }else if(ans % 3 != 0 && ans % 5 == 0){
                cout<<"Buzz";
            }else if(ans%3 == 0 && ans % 5 != 0){
                cout<<"Fizz";
            }else{
                cout<<ans;
            }
        }
    }
}