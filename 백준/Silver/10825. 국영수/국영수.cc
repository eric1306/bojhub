// Authored by: prid1306
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n;
struct Student{
    string name;
    int kor;
    int eng;
    int math;

    bool operator<(const Student& st){
        if(kor != st.kor) return kor > st.kor;
        if(eng !=st.eng) return eng < st.eng;
        if(math != st.math) return math > st.math;
        return name < st.name; //앞에서부터 사전순으로 비교
    }
};

int main(){
    FASTIO;
    cin>>n;
    vector<Student> arr(n);
    for(int i=0;i<n;i++){
        string name;
        int K, E, M;
        cin>>name>>K>>E>>M;
        arr[i] = {name, K, E, M};
    }
    sort(arr.begin(), arr.end());
    for(auto st : arr){
        cout<<st.name<<'\n';
    }
}