#include <bits/stdc++.h>
using namespace std;

vector<int> ta;
vector<int> tb;
int a[20][20];
int n;
int ans=20001;
/*
일단 두 팀원을 담는 벡터를 구하고, 
팀원이  N/2를 초과하지 않는 한 계속해서 push_back을 해준다
*/
int sumv(int idx,char ch){
	if(ch=='a'&&ta.size()==1)return 0;
	if(ch=='b'&&tb.size()==1)return 0;
	int tm=0;
	
	if(ch=='a'){
		for(int i=0;i<ta.size()-1;i++){
			tm=tm+a[ta.at(i)][idx]+a[idx][ta.at(i)];
		}
	}
	if(ch=='b'){
		for(int i=0;i<tb.size()-1;i++){
			tm=tm+a[tb.at(i)][idx]+a[idx][tb.at(i)];
		}
	}
	
	return tm;
}

void go(int a, int b,int begin, int n){
	if(ta.size()==n/2&&tb.size()==n/2){
		int ansf=abs(a-b);
		if(ansf<ans)ans=ansf;
		return;
	}
	if(ta.size()<n/2){
		ta.push_back(begin);
		a+=sumv(begin,'a');
		go(a,b,begin+1,n);
		a-=sumv(begin,'a');
		ta.pop_back();	
	}
	if(tb.size()<n/2){
		tb.push_back(begin);
		b+=sumv(begin,'b');
		go(a,b,begin+1,n);
		b-=sumv(begin,'b');
		tb.pop_back();	
	}
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
	N은 짝수
	팀 능력치: sij의 총합 sij 와 sji가 동시에 더해짐
	
	능력의 차이 최소로
	*/
	
	cin>>n; //팁 명수 입력
	for(int i=0;i<n;i++){ //능력치 입력받기
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	
	go(0,0,0,n); //최대값 받는 함수
	
	cout<<ans<<'\n';
	return 0;
}