#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string str;
	stack<char> s1;
	stack<char> s2;
	int m;
	char c;
	cin>>str;
	for(auto x:str)
		s1.push(x);
	//abcd
	cin>>m;
	while(m--){
		cin>>c;
		if(c=='L'){
			if(!s1.empty()){
				s2.push(s1.top());
				s1.pop();	
			}
		}else if(c=='D'){
			if(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
			}
		}else if(c=='B'){
			if(!s1.empty())
				s1.pop();
		}else if(c=='P'){
			cin>>c;
			s1.push(c);
		}
	}
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
	while(!s2.empty()){
		cout<<s2.top();
		s2.pop();
	}
	
	return 0;
}