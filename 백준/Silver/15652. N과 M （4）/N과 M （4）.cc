#include <bits/stdc++.h>
using namespace std;

int d[8];
bool v[9];

void nm(int cnt, int n,int m){ //수열이 비내림차순이여야 한다. (같거나 오름차순)
	if(cnt==m){ //다 찾았을 시 출력하는 함수
		for(int i=0;i<m;i++){
			cout<<d[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		if(i<d[cnt-1])continue;
		d[cnt]=i;
		nm(++cnt,n,m);
		d[--cnt]=0;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m; //1<=m<=n<=8;
	cin>>n>>m;
	nm(0,n,m);
	return 0;
}