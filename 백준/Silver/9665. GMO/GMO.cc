// Authored by: prid1306
// BOJ 9665
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int cost[4];
const int INF = 1e9;

int ATN(char c){return c == 'A' ? 0 : (c == 'C' ? 1 : (c == 'G' ? 2 : 3));}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n,m;
    cin>>n>>m;
    int ns = n.size(),ms = m.size();

    for(int i=0;i<4;i++) {cin>>cost[i];}

    vector<int> pre(ms+1, INF), cur(ms+1, INF);

    pre[0] = 0;
    for(int i=1;i<=ms;i++){
        pre[i] = pre[i-1] + cost[ATN(m[i-1])];
    }
    
    int ans = INF;
    for(int i=1;i<=ns;i++){
        cur[0] = 0;
        for(int j=1;j<=ms;j++){
            if(n[i-1] == m[j-1]){
                cur[j] = pre[j-1];
            }
            else{
                cur[j] = cur[j-1] + cost[ATN(m[j-1])];
            }
        }
        ans = min(ans, cur[ms]);
        swap(pre,cur);
    }
    cout<<ans<< "\n";
    return 0;
}