#include <iostream>
#include <string>

using namespace std;

int stack[10000];
int size_s=0;

int push(int x){
	stack[size_s++]=x;
	return stack[size_s-1];
}
int pop(){
	if(size_s==0){
		return -1;
	}
	int k=stack[size_s-1];
	stack[--size_s]=0;
	return k;
}
int size(){
	return size_s;
}
int top(){
	if(size_s==0)
		return -1;
	return stack[size_s-1];
}
int empty(){
	if(size_s==0)
		return 1;
	else
		return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string ord;
	int x,N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>ord;
		if(ord=="push"){
			cin>>x;
			push(x);
		}else if(ord=="pop")
			cout<<pop()<<'\n';
		else if(ord=="size")
			cout<<size()<<'\n';
		else if(ord=="empty")
			cout<<empty()<<'\n';
		else
			cout<<top()<<'\n';
	}
	
}