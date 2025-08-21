// Authored by: prid1306
// BOJ 10942 팰린드롬 재풀이
#include <iostream>
#include <vector>
using namespace std;
int a[2001];
int d[2001][2001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i]; d[i][i] = 1;} //한자리수는 무조건 팰린드롬이니까.
    for(int i=1;i<n;i++){
        for(int j = 1;j <= n - i;j++){
            //cout<<j<<' '<<i+j<<' '<<a[i]<<' '<<a[j]<<'\n';
            if(i == 1){
                d[j][j + i] = a[j] == a[j+i] ? 1 : 0;
            }else{
                if(a[j] == a[j+i]) d[j][j + i] = d[j + 1][j + i - 1];
                else d[j][j+i] = 0;
            }
            //cout<<"d["<<j<<"]["<<j+i<<"]: "<<d[j][j+i]<<'\n';
        }
    }
    cin>>m;
    while(m--){
        int st,en;cin>>st>>en;
        /*
        d[st][en] 의 값이 궁금한거임
        만약 a[st] == a[en]이라면 d[st+1][d[en-1]이 팰린드롬인지 파악하면 된다.
        만약 st + 1 <= en - 1  이라면 d[st][en] = d[st + 1][en - 1]을 파악
        st + 1 > en -  1 이라면 범위 초과이기때문에 무조건 0
        근데, 1 4를 예로 들면, d[1][4]이고, a[1] == a[4]라면, d[2][3]의 값이 들어가게 되는데, 이건 구할 수 없다.
        그러니까 값을 구하는 순서를
        1 2 / 2 3 / 3 4 / .... n-1 n
        1 3 / 2 4 / 3 5 / ...... / n-2 n/
        1 4 / 2 5 / 3 6 / .... / n - 3 / n
        순서대로 구해야겠네
        */
        cout<<d[st][en]<<'\n';
    }
}