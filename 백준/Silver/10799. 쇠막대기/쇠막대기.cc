#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	/*
	결국 요점은
	
	각 파이프 별로 레이저가 몇번 지나갔냐?? 이거네
	
	각 파이프스타트점 부터(열린 괄호)
	괄호가 닫힐때 까지 ()레이저를 만난 횟수를 계산하면 된다.
	stack에 넣고
	분쇄 나올때 마다 size를 piece에 더해주기
	닫는 괄호 나오면 1만 더해주기(왜냐하면 총 두번 잘렸으니까 세피스)
	*/
	string str;
	getline(cin,str);
	stack<char> s;
	int piece=0;
	for(int i=0;i<str.size();i++){
		if(str[i]=='('){
			if(str[i+1]==')'){
				piece+=s.size();
				i++;
			}
			else
				s.push(str[i]);
		}else if(str[i]==')'){
			if(!s.empty()){
				s.pop();
				piece++;
			}
		}
	}
	cout<<piece;
	return 0;
}