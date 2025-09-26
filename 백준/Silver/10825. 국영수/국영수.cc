// Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <string>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n;
struct Student{
    string name;
    int kor;
    int eng;
    int math;
};

Student arr[100001];


bool cmp(Student a, Student b)
{
    if(a.kor != b.kor) return a.kor > b.kor;
    if(a.eng !=b.eng) return a.eng < b.eng;
    if(a.math != b.math) return a.math > b.math;
    return a.name < b.name; //앞에서부터 사전순으로 비교
}

int main(){
    FASTIO;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        int KoreanScore, EnglishScore, MathmaticsScore;
        cin>>name>>KoreanScore>>EnglishScore>>MathmaticsScore;
        arr[i] = Student{name, KoreanScore, EnglishScore, MathmaticsScore};
    }
    sort(arr, arr + n, cmp);
    for(int i=0;i<n;i++){
        cout<<arr[i].name<<'\n';
    }
}