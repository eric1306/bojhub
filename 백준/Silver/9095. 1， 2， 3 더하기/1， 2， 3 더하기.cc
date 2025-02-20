#include <iostream>
using namespace std;

int sum12(int n){
	int sum=0;
	if(n==0)
		return 1;
	if(n>=1)
		sum+=sum12(n-1);
	if(n>=2)
		sum+=sum12(n-2);
	if(n>=3)
		sum+=sum12(n-3);
	
	
	return sum;
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		cout<<sum12(n)<<'\n';
	}
	
	
	return 0;
}