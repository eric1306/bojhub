#include <iostream>
#include <queue>
#include <utility>
using namespace std;

string arr[4];
int visit[4];
int t,saw,dir;
queue<pair<int,int>> q;

void Rotate(int sn, int d)
{
    
    if(d == 1)
    {
        char tmp = arr[sn][7];
        for(int i=7;i>0;--i)
        {
            arr[sn][i] = arr[sn][i-1];
        }
        arr[sn][0] = tmp;
    }
    else if(d == -1)
    {
        char tmp = arr[sn][0];
        for(int i=0;i<7;i++)
        {
            arr[sn][i] = arr[sn][i+1];
        }
        arr[sn][7] = tmp;
    }
}
int resultScore()
{
    int ret = 0;
    if(arr[0][0] == '1') ret += 1;
    if(arr[1][0] == '1') ret += 2;
    if(arr[2][0] == '1') ret += 4;
    if(arr[3][0] == '1') ret += 8;
    return ret;
}

void RotationSaw(int s, int d)
{
    //이 함수에 들어온 이상, 이 친구는 무조건 회전이 가능함(가정)
    visit[s-1] = 1;
    q.push({s-1,d});
    if(s == 1)
    {
        //오른쪽 검사
        if(arr[s-1][2]!=arr[s][6] && !visit[s])
        {
            d*=-1;
            RotationSaw(s+1,d);
        }
    }
    else if(s == 2 || s == 3)
    {
        if(d == 1)
        {
            //오른쪽 검사
            if(arr[s-1][2]!=arr[s][6] && !visit[s])
            {
                
                RotationSaw(s+1,-1);
            }
            //왼쪽 검사
            if(arr[s-1][6]!=arr[s-2][2] && !visit[s-2])
            {
                d*=-1;
                RotationSaw(s-1,-1);
            }
        }
        else if(d == -1)
        {
            //왼쪽 검사
            if(arr[s-1][6]!=arr[s-2][2] && !visit[s-2])
            {
                RotationSaw(s-1,1);
            }
            //오른쪽 검사
            if(arr[s-1][2]!=arr[s][6] && !visit[s])
            {
                RotationSaw(s+1,1);
            }
        }
    }
    else
    {
        //왼쪽 검사
        if(arr[s-1][6]!=arr[s-2][2] && !visit[s-2])
        {
            d*=-1;
            RotationSaw(s-1,d);
        }
    }

}

void printsaw()
{
    for(auto c : arr) cout<<c<<'\n';
    cout<<"-------\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<4;i++) 
        cin>>arr[i];

    cin>>t;
    while(t--)
    {
        fill(visit,visit+4,0);
        cin>>saw>>dir;    
        RotationSaw(saw, dir);
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            Rotate(p.first,p.second);
        }
        ///printsaw();
    }
    cout<<resultScore();
}