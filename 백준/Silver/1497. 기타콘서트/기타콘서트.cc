//Authored by: prid1306
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n,m;
long long state[11];
int _min = 0x3fffffff;
long long minsongs = 0;
long long _max = 0;
bool visit[11];
void check(int count)
{
    if(count !=0 && count <= n)
    {
        long long ret = 0;
        for(int i=0;i<n;i++)
        {
            if(visit[i]) ret = ret | state[i];
        }
        if(ret == 0) return;
        
        if(ret > minsongs)
        {
            _min = count;
            minsongs = ret;
        }
        else if(ret == minsongs)
        {
            if(_min > count)
            {
                _min = count;
                minsongs = ret;
            }
        }
        if(count == n) return;
    }

    for(int i=0;i<n;i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            check(count+1);
            visit[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        _max = _max<<1;
        _max+=1;
    }

    for(int i=0;i<n;i++)
    {
        string tmp, songs;
        cin>>tmp>>songs;
        for(int j=0;j<m;j++)
        {
            state[i] = state[i]<<1;
            if(songs[j] == 'Y')
            {
                state[i]++;
            }
        }
    }
    check(0);
    if(_min == 0x3fffffff) cout<<-1;
    else cout<<_min;
}