//Authored by: prid1306
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int board[32][20];
vector<pair<int,int>> coords;

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
    int sz = coords.size();
    for(int i=st_i;i<sz;i++){
        int nx = coords[i].first;
        int ny = coords[i].second;
        if(board[nx][ny]==0 && (board[nx][ny-2] != 9 && board[nx][ny+2] !=9)){
            board[nx][ny] = 9;
            bt(k+1,i+1);
            board[nx][ny] = 0;
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
    }
    for (int i = 0; i < h; i++) for (int j = 1; j < n*2-1; j+=2) {
        if (board[i][j - 2] || board[i][j] || board[i][j + 2]) continue;
        coords.push_back({i, j});
    }
    bt(0,0);
    if(ans == 4) cout<<-1;
    else cout<<ans;
}