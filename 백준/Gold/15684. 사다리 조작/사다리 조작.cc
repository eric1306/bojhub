//Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int board[300][20];
int visit[300][20];

int n,m,h;
int ans = 4;
void printboard(){
    cout<<"------------"<<'\n';
    for(int i=0;i<h;i++){
        for(int j=0;j<n*2;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<"\n";
    }
    cout<<"------------"<<'\n';
}

bool check(){
    for(int i=0;i<n*2;i+=2){
        int tmp = i;
        for(int j=0;j<h;j++){
            if(board[j][tmp+1] == 9) tmp+=2;
            else if(tmp > 1 && board[j][tmp-1] == 9) tmp-=2;
        }
        if(tmp !=i) return false;
    }
    return true;
}

void bt(int k,int st_i){
    //printboard();
    if(k > 3) return;
    if(check()){
        //cout<<"k is: "<<k<<'\n';
        if(ans > k) ans = k;
        return;
    }
    for(int i=st_i;i<h;i++){
        for(int j=1;j<n*2;j+=2){
            if(!visit[i][j] && board[i][j]==0 && (board[i][j-2]!=9 && board[i][j+2]!=9)){
                visit[i][j] = 1;
                board[i][j] = 9;
                bt(k+1,i);
                board[i][j] = 0;
                visit[i][j] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>h;
    for(int i=0;i<h;i++) for(int j=0;j<n;j++){
        board[i][j*2] = 1;    
    }
    int row,col;
    for(int i=0;i<m;i++){
        cin>>row>>col;
        board[row-1][(col-1)*2+1] = 9;
        visit[row-1][(col-1)*2+1] = 1;
    }
    bt(0,0);
    if(ans == 4) cout<<-1;
    else cout<<ans;
}