#include <iostream>
#include <utility>
#include <queue>
using namespace std;

const int LMT = 100001;
int board[LMT+2];
int sis, bro;
queue<int> q;

void teleport(int num){
    int tmp = num;
    if(!tmp) return;
    while(tmp < LMT && !board[bro]){
        if(!board[tmp]){
            board[tmp] = board[num];
            q.push(tmp);
            if(tmp == bro) return;
        }
        tmp <<= 1;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>sis>>bro;
    board[sis] = 1;
    q.push(sis);
    teleport(sis);
    while(!board[bro]){
        int v = q.front(); q.pop();
        vector<int> nvLst = {v+1, v-1};
        for(int nv : nvLst){
            if(nv < 0 || LMT <= nv) continue;
            if(board[nv]) continue;
            board[nv] = board[v]+1;
            q.push(nv);
            teleport(nv);
        }
    }
    cout<<board[bro]-1;
}