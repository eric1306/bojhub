#include <iostream>
#include <vector>
using namespace std;

int GCD(int a,int b){
	if(b==0)
		return a;
	else
		return GCD(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t,n,q;
	long long ans=0;
	vector<int> vec;
	cin>>t;
	while(t--){
		cin>>n;
		for(int p=0;p<n;p++){
			cin>>q;
			vec.push_back(q);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans+=GCD(vec.at(i),vec.at(j));
			}
		}
		cout<<ans<<'\n';
		vec.clear();
		ans=0;
	}
    return 0;
}