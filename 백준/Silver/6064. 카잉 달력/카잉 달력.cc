#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int TC,m,n,x,y;
	cin>>TC;
	while(TC--){
		cin>>m>>n>>x>>y;
		int ans=-1;
		for(int i=x-1;i<m*n;i+=m){
			if(i%n==y-1){
				ans=i+1;
				break;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}