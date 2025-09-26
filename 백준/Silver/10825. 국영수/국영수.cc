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

    bool operator<(Student st){
        if(kor != st.kor) return kor > st.kor;
        if(eng !=st.eng) return eng < st.eng;
        if(math != st.math) return math > st.math;
        return name < st.name; //앞에서부터 사전순으로 비교
    }
};
Student arr[100001];

int main(){
    FASTIO;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        int KoreanScore, EnglishScore, MathmaticsScore;
        cin>>name>>KoreanScore>>EnglishScore>>MathmaticsScore;
        arr[i] = Student{name, KoreanScore, EnglishScore, MathmaticsScore};
    }
    sort(arr, arr + n);
    for(int i=0;i<n;i++){
        cout<<arr[i].name<<'\n';
    }
}