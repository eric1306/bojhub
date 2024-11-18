#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[9];
int n=9;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(sum-arr[i]-arr[j]==100){
				for(int k=0;k<n;k++){
					if(i==k||j==k) continue;
					cout<<arr[k]<<'\n';	
				}
				return 0;
			}
		}
	}
}