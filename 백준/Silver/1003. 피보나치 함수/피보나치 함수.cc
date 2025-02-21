#include <iostream>

#define x first
#define y second

using namespace std;
/*idx번째 수를 위해 필요한 0과 1 개수*/

pair<int,int> operator+(const pair<int,int>& a1,const pair<int,int>& a2)
{
    pair<int,int> p = {a1.x + a2.x,a1.y+a2.y};
    return p;
}
pair<int,int> d[41];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    d[0] = {1,0};
    d[1] = {0,1};
    for(int i=2;i<41;i++){
        d[i] = d[i-1]+d[i-2];
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<d[n].x<<' '<<d[n].y<<'\n';
    }
}