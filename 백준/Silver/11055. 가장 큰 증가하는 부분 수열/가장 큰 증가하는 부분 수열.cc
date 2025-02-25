#include <iostream>
#include <algorithm>
using namespace std;

int d[1000];
int a[1000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n; //n받기
	for(int i=0;i<n;i++){
		cin>>a[i]; //수열 A이루는 값들 받기
	}
	
	for(int i=0;i<n;i++){
		d[i]=a[i];
		for(int j=0;j<i;j++){
			if(a[j]<a[i]&&d[i]<d[j]+a[i])
				d[i]=d[j]+a[i];
		}
	}
	int ans=d[0];
	for(int i=0;i<n;i++){
		if(ans<d[i])
			ans=d[i];
	}
	cout<<ans;
	return 0;
}