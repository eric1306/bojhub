#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int N,temp;
	int arr[1000];
	
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(int i=0;i<N;i++){
		cout<<arr[i]<<'\n';
	}
	
}