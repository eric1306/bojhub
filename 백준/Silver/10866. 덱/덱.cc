#include <iostream>
#include <string>
using namespace std;
typedef struct{
	int d[20000]; //왜냐하면 최악의 경우가 10000번의 작업이 모두 ,push_front 또는 back일수 있으므로
	//0~9999의 인덱스는 front, 10000~19999 index는 back을 위한 자리
	int begin=0;
	int end=0;
	
	void push_front(int X){
		d[9999+begin]=X;
		begin--;
	}
	void push_back(int X){
		d[10000+end]=X;
		end++;
	}
	void pop_front(){
		if(begin==end)
			cout<<"-1"<<'\n';
		else{
			cout<<d[10000+begin]<<'\n';
			d[10000+begin]=0;
			begin++;
		}
	}
	void pop_back(){
		if(begin==end)
			cout<<"-1"<<'\n';
		else{
			cout<<d[9999+end]<<'\n';
			d[9999+end]=0;
			end--;
		}
	}
	void size(){
		cout<<end-begin<<'\n';
	}
	void empty(){
		if(begin==end)
			cout<<"1"<<'\n';
		else
			cout<<"0"<<'\n';
	}
	void front(){
		if(begin==end)
			cout<<"-1"<<'\n';
		else
			cout<<d[10000+begin]<<'\n';
	}
	void back(){
		if(begin==end)
			cout<<"-1"<<'\n';
		else
			cout<<d[9999+end]<<'\n';
	}
}Deque;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Deque deque;
	int T,X;
	string str;
	cin>>T;
	while(T--){
		cin>>str;
		if(str=="push_front"){
			cin>>X;
			deque.push_front(X);
		}else if(str=="push_back"){
			cin>>X;
			deque.push_back(X);
		}else if(str=="pop_front"){
			deque.pop_front();
		}else if(str=="pop_back"){
			deque.pop_back();
		}else if(str=="size"){
			deque.size();
		}else if(str=="empty"){
			deque.empty();
		}else if(str=="front"){
			deque.front();
		}else if(str=="back"){
			deque.back();
		}
	}
	
}