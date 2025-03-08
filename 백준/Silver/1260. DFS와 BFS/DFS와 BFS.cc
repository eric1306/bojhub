#include <bits/stdc++.h>
using namespace std;
/*
방문정점 여러개일 때 작은것 먼저 방문, 방문X시 종료
1~N번
인접행렬로 구현
*/
bool a[10001][10001]; //간선 true표시하는 bool 배열
bool check_dfs[1001]; //dfs함수에서 방문했는지 체크하는 arr
bool check_bfs[1001]; //bfs함수에서 방문했는지 체크하는 arr
stack<int> s; 
queue<int> q;
int n;
void dfs(int k){ //dfs구하는 함수
	s.push(k);
	check_dfs[k]=true;
	cout<<k<<' ';
	for(int i=1;i<=n;i++){ //모든 정점과 비교
		if(!check_dfs[i]&&a[k][i]){ //i를 아직 사용하지 않았고, k와 i 사이에 간선이 존재한다면
			dfs(i); //그 수로 다시 깊이 우선 탐색하기
		}
	}
}

void bfs(int v){
	check_bfs[v]=true;
	q.push(v);
	cout<<v<<' ';
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=1;i<=n;i++){
			if(!check_bfs[i]&&a[x][i]){
				q.push(i);
				check_bfs[i]=true;
				cout<<i<<' ';
			}
		}
	}
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int m,v,row,column;
	cin>>n>>m>>v;
	for(int i=0;i<m;i++){ //간선 입력 받기
		cin>>row>>column;
		a[row][column]=true; //방향 없는 간선이므로 반드시 양쪽 모두 체크
		a[column][row]=true;
	}
	//dfs
	dfs(v);
	cout<<'\n';
	//bfs
	
	bfs(v);
	
	return 0;
}