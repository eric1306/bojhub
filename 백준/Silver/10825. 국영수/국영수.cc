// Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n;
tuple<string, int, int, int> arr[100001];

bool IsBig(char a){
    return a >= 'A' && a <= 'Z';
}
bool cmp(tuple<string, int, int, int> a, tuple<string, int, int, int> b)
{
    string a_name,b_name;
    int a_kor, a_eng, a_math, b_kor, b_eng, b_math;
    tie(a_name, a_kor, a_eng, a_math) = a;
    tie(b_name, b_kor, b_eng, b_math) = b;

    if(a_kor > b_kor) return true;
    else if(a_kor == b_kor){
        if(a_eng < b_eng)
            return true;
        else if(a_eng == b_eng){
            if(a_math > b_math)
                return true;
            else if(a_math == b_math){
                for(int i=0;i<a_name.size() > b_name.size() ? b_name.size() : a_name.size();i++){
                    if(a_name[i] == b_name[i]) continue;

                    if(IsBig(a_name[i]) && !IsBig(b_name[i])) return true;
                    else if(!IsBig(a_name[i]) && IsBig(b_name[i])) return false;
                    else if(a_name[i] < b_name[i]) return true;
                    else return false;
                }
            }
        }
    }
    return false;
}

int main(){
    FASTIO;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        int KoreanScore, EnglishScore, MathmaticsScore;
        cin>>name>>KoreanScore>>EnglishScore>>MathmaticsScore;
        arr[i] = tuple(name, KoreanScore, EnglishScore, MathmaticsScore);
    }
    sort(arr, arr + n, cmp);
    for(int i=0;i<n;i++){
        cout<<get<0>(arr[i])<<'\n';
    }
}