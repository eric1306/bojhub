#include <iostream>
#include <sstream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
/*****************************
제한시간 1초니 O(N) 시간복잡도를 가져야함. TC가 100개이기 때문
전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.

*****************************/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //tc 개수
    int t;
    cin>>t;
    while(t--){
        int flag = true;
        bool reverse_arr = false;
        //명령어
        string n;
        cin>>n;
        //배열 길이
        int len;
        cin>>len;
        //deque에 입력값 담기
        deque<int> d;
        string op;
        cin>>op;
        string tmp="";
        //[] 제거
        for(char c : op){
            if(c!='[' && c!=']'){
                tmp+=c;
            }
        }
        // , 제거
        char sep = ',';
        istringstream iss(tmp);
        string str_buf;
        string tmp2="";
        while(getline(iss, str_buf, sep)) d.push_back(stoi(str_buf));
        for(char op : n){
            if(op == 'R'){
                reverse_arr = !reverse_arr;
            }else{ /*op == D*/
                if(!d.empty()){
                    if(reverse_arr) d.pop_back();
                    else d.pop_front();
                }
                else {
                    cout<<"error";
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            if(d.size()!=0) cout<<'[';
            else cout<<"[]";
            if(reverse_arr){
                for(int i = d.size()-1; i >= 0; i--){
                    if(i == 0) cout<<d[i]<<']';
                    else cout<<d[i]<<',';
                }
            }else{
                for(int i=0;i<d.size();i++){
                    if(i == d.size()-1) cout<<d[i]<<']';
                    else cout<<d[i]<<',';
                }
            }
            
        }
        cout<<'\n';
    }
}