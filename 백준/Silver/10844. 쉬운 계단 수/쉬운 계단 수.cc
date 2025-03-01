#include <iostream>
using namespace std;

long long D[101][101];
const long long mod=1000000000;
int limit=100;

void ansf(){
	for(int j=1;j<=9;j++){ //여기는 인정 
		D[1][j]=1;
	}
	D[1][0]=0;
	for(int i=2;i<=limit;i++){
		for(int j=0;j<=9;j++){
			if(j-1>=0&&j+1<10){//1~8 사이
				D[i][j]=D[i-1][j-1]%mod+D[i-1][j+1]%mod;	
			}else if(j==0){
				D[i][j]=D[i-1][j+1]%mod;
			}else if(j==9){
				D[i][j]=D[i-1][j-1]%mod;
			}
			D[i][j]%=mod;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long ans=0;
	cin>>n;
	ansf();
	for(int i=0;i<=9;i++){
		ans+=D[n][i]%mod;
	}
	cout<<ans%mod;
	
	return 0;
}