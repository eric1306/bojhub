#include <bits/stdc++.h>
using namespace std;

int a[501][501];
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m,ans=-1;
	cin>>n>>m; //n,m 입력받기 4<=m,n<=500
	for(int i=1;i<=n;i++){ //각 배열 값 들 입력 받기
		for(int j=1;j<=m;j++){
			cin>>a[i][j]; //<=1000
		}
	}
	int sum;
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=m;j++){
			if(j+3<=m){//2 1*4 tetromino
				sum=a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3];
				if(ans<sum)
					ans=sum;
			}
			if(i+3<=n){ //1 4*1 tetromino
				sum=a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j];
				if(ans<sum)
					ans=sum;
			}
			if(i+1<=n&&j+1<=m){ //3 2*2 tetromino
				sum=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
				if(ans<sum)
					ans=sum;
			}
			if(i+2<=n&&j+1<=m){ //4 j2 i1 tetromino
				sum=a[i][j]+a[i+1][j]+a[i+2][j]+a[i+2][j+1];
				if(ans<sum)
					ans=sum;
			}
			if(i+2<=n&&j>=1){ //5i1 j2 tetromino
				sum=a[i][j]+a[i+1][j]+a[i+2][j]+a[i+2][j-1];
				if(ans<sum)
					ans=sum;
			}
			if(j+2<=m&&i>=1){//6 i2 j1 tetromino
				sum=a[i][j]+a[i][j+1]+a[i][j+2]+a[i-1][j+2];
				if(ans<sum)
					ans=sum;
			}
			if(i+1<=n&&j+2<=m){ //7 i2 j1 tetromino
				sum=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+2];
				if(ans<sum)
					ans=sum;
			}
			if(i+2<=n&&j+1<=m){ //8,9 이 경우로 i1 j2 tetromino 둘 다 처리 가능
				sum=a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+2][j+1];
				if(ans<sum)
					ans=sum;
				sum=a[i][j]+a[i][j+1]+a[i+1][j]+a[i+2][j];
				if(ans<sum)
					ans=sum;
			}
			if(i+1<=n&&j+2<=m){ //10 i2 j1 tetromino
				sum=a[i][j]+a[i+1][j]+a[i][j+1]+a[i][j+2];
				if(ans<sum)
					ans=sum;
				
			}
			if(i+1<=n&&j+2<=m){ //11 j1 i2 tetromino
				sum=a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2];
				if(ans<sum)
					ans=sum;
			}
			if(i+2<=n&&j+1<=m){ //12
				sum=a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j+1];
				if(ans<sum)
					ans=sum;
			}
			if(i>=1&&j+2<=m){//13
				sum=a[i][j]+a[i][j+1]+a[i-1][j+1]+a[i-1][j+2];
				if(ans<sum)
					ans=sum;
			} 
			if(i>=1&&i+1<=n&&j+1<=m){//14
				sum=a[i][j]+a[i+1][j]+a[i][j+1]+a[i-1][j+1];
				if(ans<sum)
					ans=sum;
			} 
			if(i+1<=n&&j+2<=m){ //15
				sum=a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+1][j+2];
				if(ans<sum)
					ans=sum;
			}
			if(i+1<=n&&j+2<=m){ //16
				sum=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1];
				if(ans<sum)
					ans=sum;
			}
			if(i>=1&&i+1<=n&&j+1<=m){ //17
				sum=a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i-1][j+1];
				if(ans<sum)
					ans=sum;
			}
			if(i>=1&&j+1<=m){ //18
				sum=a[i][j]+a[i][j+1]+a[i-1][j+1]+a[i][j+2];
				if(ans<sum)
					ans=sum;
			}
			if(i+2<=n&&j+1<=m){
				sum=a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j];
				if(ans<sum)
					ans=sum;
			}
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}