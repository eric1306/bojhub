#include <iostream>
#include <algorithm>
using namespace std;

int d[1000];
int a[1000];
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=0;i<n;i++){
		d[i]=a[i];
		for(int j=0;j<i;j++){
            /*i보다 앞에있는 원소들중에서 a보다 크면서, 
            해당 원소까지의 가장 큰 감소 부분 수열에 i번째 원소를 더한 값이 
            d[i]보다 작아야함
            (d[i]는 가장 큰 감소하는 부분수열이 본인까지라고 가정하는 놈)*/
			if(a[j]>a[i]&&d[i]<d[j]+a[i]) 
				d[i]=d[j]+a[i];
		}
	}
	int ans=d[0];
	for(int i=0;i<n;i++) if(ans<d[i]) ans=d[i];
	cout<<ans;
	return 0;
}