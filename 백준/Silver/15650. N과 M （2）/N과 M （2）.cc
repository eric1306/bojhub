#include <bits/stdc++.h>
using namespace std;

bool c[10]={false,};
int a[10];

void go(int index, int n,int m){
	if(index==m){
		for(int i=0;i<m;i++){
			cout<<a[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		if(c[i])continue;
		if(a[index-1]>i)continue;
		c[i]=true;
		a[index]=i;
		go(index+1,n,m);
		c[i]=false;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	go(0,n,m);
	
	return 0;
}