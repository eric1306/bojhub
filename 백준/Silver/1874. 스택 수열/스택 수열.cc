#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,k,i;
	int j=1;
	stack<int> s;
	vector<char> vec;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;
		if(s.empty()){
			s.push(j++);
			vec.push_back('+');
		}
		if(k==s.top()){
			vec.push_back('-');
			s.pop();
		}else{
			for(;j<=k;j++){
				vec.push_back('+');
				s.push(j);
			}
			if(k==s.top()){
				vec.push_back('-');
				s.pop();
			}else{
				cout<<"NO"<<'\n';
				break;
			}
		}
	}
	if(i==n+1){
		for(int l=0;l<vec.size();l++)
			cout<<vec.at(l)<<'\n';
	}
	return 0;
}