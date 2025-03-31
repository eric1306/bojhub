#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int E,S,M;
	int e=1,s=1,m=1;
	cin>>E>>S>>M;
	for(int i=1;;i++){
		if(e==E&&s==S&&m==M){
			cout<<i<<'\n';
			break;
		}
		e+=1;
		s+=1;
		m+=1;
		if(e==16)
			e=1;
		if(s==29)
			s=1;
		if(m==20)
			m=1;
		
	}
	
	return 0;
}