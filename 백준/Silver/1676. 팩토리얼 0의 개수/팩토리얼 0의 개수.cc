#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int N,num_2=0,num_5=0;
	cin>>N;
	for(int i=1;i<=N;i++){
		int i_=i;
		while(i_%2==0){
			num_2++;
			i_=i_/2;
		}
		while(i_%5==0){
			num_5++;
			i_=i_/5;
		}
	}
	int l=num_2>num_5?num_5:num_2;
	cout<<l<<'\n';
    return 0;
}