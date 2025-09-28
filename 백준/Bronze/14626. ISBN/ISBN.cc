// Authored by: prid1306
#include <iostream>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
const int ISBNLength = 13;
int modList[10] = {0, 21, 12, 33, 24, 15, 6, 27, 18, 9};
int main(){
    FASTIO;
    string s;cin>>s;
    int targetIdx;
    for(int i=0;i<ISBNLength; i++){ //*의 위치 찾기
        if(s[i] == '*'){
            targetIdx = i;
            break;
        }
    }
    int ans = 0;
    for(int i=0;i<ISBNLength;i++){
        if(i == targetIdx) continue;
        else if(i == ISBNLength - 1){
            ans += (int)(s[i] - '0');
            break;
        }
        ans += (int)(s[i] - '0') * (i%2 == 0 ? 1 : 3);
    }   
    ans%=10;
    
    if(ans == 0){
        cout<<0;
    }
    else if(targetIdx%2 == 0){
        cout<<10 - ans;
    }else{
        //여기에는 나머지 값만 들어옴 21 -> 1, 16 -> 6
        //따라서 10씩 더하면서 값을 찾아야함.
        cout<<modList[10 - ans]/3;
    }
}