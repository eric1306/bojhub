#include <iostream>
using namespace std;
int d[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
	만약 작거나 같은 제일 큰 제곱수를 빼버리는 연산을 진행하면
	
	32라는 오차가 발생함
	32=5^2+2^2+1^2+1^2+1^2 (6)
	32=4^2+4^2(2)
	*/
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		d[i]=i; //최대 연산횟수를 넣어주기
		for(int j=1;j*j<=i;j++){ //1~sqrt(i)의 제곱 까지가 마지막 수라면 영향 받는 d[i]들 작성
			if(d[i]>d[i-j*j]+1){
				d[i]=d[i-j*j]+1;
			}
		}
	}
	cout<<d[n]<<'\n';
	return 0;
}