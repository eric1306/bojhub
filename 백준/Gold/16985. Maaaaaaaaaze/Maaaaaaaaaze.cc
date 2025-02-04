#include <iostream>
#include <utility>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int arr[5][5][5];
int arr2[5][5][5];
int arr3[5][5][5];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int spin[5];

int visit[5];
int btarr[5];

int visitarr[5][5][5];

int _min = 125;
int ans;
int sp[4][3]={
    {0,0,0},
    {0,0,4},
    {0,4,0},
    {0,4,4},
};

bool OOP(int x, int y, int z){
    return (x < 0 || x >=5 || y < 0 || y >=5 || z < 0 || z >=5);
}

void clearvisitarr(){
    for(int i=0;i<5;i++) for(int j=0;j<5;j++){
        fill(visitarr[i][j],visitarr[i][j]+5,0);
    }
}

int BFS(){
    //cout<<"spin: ";
    //for(auto c : spin) cout<<c;
    //cout<<"\nbtarr: ";
    //for(auto k : btarr) cout<<k;

    queue<tuple<int,int,int,int>> q;
    for(int i=0;i<4;i++)
    {
        clearvisitarr();
        while(!q.empty())q.pop();
        if(arr3[sp[i][0]][sp[i][1]][sp[i][2]] == 0) continue;

        q.push({sp[i][0], sp[i][1],sp[i][2],0/*dist*/});

        tuple<int,int,int> arrive = {4-sp[i][0],4-sp[i][1],4-sp[i][2]};

        if(arr3[get<0>(arrive)][get<1>(arrive)][get<2>(arrive)] == 0) continue; 
        //cout<<"start!: ("<<sp[i][0]<<","<<sp[i][1]<<","<<sp[i][2]<<")"<<'\n';

        visitarr[sp[i][0]][sp[i][1]][sp[i][2]] = 1;
        while(!q.empty())
        {
            tuple<int,int,int,int> t = q.front();
            q.pop();
            for(int j=0;j<6;j++)
            {
                int nx = get<0>(t) + dx[j];
                int ny = get<1>(t) + dy[j];
                int nz = get<2>(t) + dz[j];
                if(OOP(nx,ny,nz) || visitarr[nx][ny][nz] || arr3[nx][ny][nz] == 0) continue;
                if(nx == get<0>(arrive) && ny == get<1>(arrive) && nz == get<2>(arrive)){
                    //cout<<"return!"<<'\n';
                    return (get<3>(t)+1);
                }
                visitarr[nx][ny][nz] = 1;
                q.push({nx,ny,nz,get<3>(t)+1});
                //cout<<"Push queue!: ("<<nx<<","<<ny<<","<<nz<<") dist: "<<get<3>(t)+1<<'\n';
            }
        }
    }
    return 0;
}

void swaparr(){
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) for(int k=0;k<5;k++){
        arr3[i][j][k] = arr2[btarr[i]][j][k];
    }
}




void BT(int k){
    if(k == 5){
        swaparr();
        clearvisitarr();
        int ans = BFS();
        if(ans!=0){
            if(_min > ans)
            {
                //cout<<ans<<'\n';
                _min = ans;
            }
        }
        return;
    }
    for(int i=0;i<5;i++){
        if(!visit[i]){
            btarr[k] = i;
            visit[i]=1;
            BT(k+1);
            visit[i] = 0;
            btarr[k] = 0;
        }
    }
}

void Rotate(int idx){
    int tmp[5][5];
    for(int i=0;i<5;i++) for(int j=0;j<5;j++){
        tmp[i][j] = arr2[idx][i][j];
    }
    for(int i=0;i<5;i++) for(int j=0;j<5;j++){
        arr2[idx][i][j] = tmp[j][5-1-i];
    }
}
void printarr(int idx)
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<arr2[idx][i][j];
        }
        cout<<'\n';
    }
}

void copyarr(){
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) for(int k=0;k<5;k++){
        arr2[i][j][k] = arr[i][j][k];
    }
}
//5^12승 이하로 계산
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<5;i++) for(int j=0;j<5;j++) for(int k=0;k<5;k++){
        cin>>arr[i][j][k];
    }
    //1024번의 케이스 보기 00000~33333(1024)
    for(int i=0;i<(1<<2*5);i++){
        copyarr();
        int tmp = i;
        for(int j=4;j>=0;--j){//[0,0,0,0]
            spin[j] = tmp%4;
            tmp/=4;
        }
        for(int j=4;j>=0;--j){
            int tmp = spin[j];
            while(tmp--){
                Rotate(j);
            }
        }
        //돌려진 판 5개 존재->판 스왑하면서 각각 BFS
        BT(0);
        fill(visit,visit+5,0);
    }
    cout<<(_min == 125 ? -1 : _min);
}