#include <iostream>

using namespace std;
typedef struct{
	int q[10001];
	int begin=0;
	int end=0;
	
	void push(int X){
		q[end++]=X;
	}
	void pop(){
		if(end-begin==0)
			cout<<"-1"<<'\n';
		else{
			int k=q[begin];
			q[begin++]=0;
			cout<<k<<'\n';
		}
	}
	void size(){
		cout<<end-begin<<'\n';
	}
	void empty(){
		if(end-begin==0)
			cout<<'1'<<'\n';
		else
			cout<<'0'<<'\n';
	}
	void front(){
		if(end-begin==0)
			cout<<"-1"<<'\n';
		else
			cout<<q[begin]<<'\n';
	}
	void back(){
		if(end-begin==0)
			cout<<"-1"<<'\n';
		else
			cout<<q[end-1]<<'\n';
	}
}queue;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t,p;
	string s;
	queue q_;
	cin>>t;
	while(t--){
		cin>>s;
		if(s=="push"){
			cin>>p;
			q_.push(p);
		}else if(s=="pop"){
			q_.pop();
		}else if(s=="size"){
			q_.size();
		}else if(s=="empty"){
			q_.empty();
		}else if(s=="front"){
			q_.front();
		}else if(s=="back"){
			q_.back();
		}
	}
}