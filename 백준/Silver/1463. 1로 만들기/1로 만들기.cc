#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	int d[1000001]={0,};
	cin>>n;
	d[1]=0;
	for(int i=2;i<=n;i++){
		d[i]=d[i-1]+1;
		if(i%2==0&&d[i]>d[i/2]+1){
			d[i]=d[i/2]+1;
		}
		if(i%3==0&&d[i]>d[i/3]+1){
			d[i]=d[i/3]+1;
		}
	}
	cout<<d[n];
	
	return 0;
}