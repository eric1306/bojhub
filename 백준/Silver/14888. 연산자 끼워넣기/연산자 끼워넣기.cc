#include <iostream>
using namespace std;

int n;
int num[12];
/*+, -, x, /*/
int ysj[4];
int isused[4];
char res[12];
int _max = -1'000'000'000;
int _min = 1'000'000'000;

int ys()
{
    int ans=num[0];
    for(int i=0;i<n-1;i++)
    {
        int t1 = ans,t2=num[i+1];
        if(res[i] == '+')
        {
            t2 =t1+t2;
        }
        else if(res[i] == '-')
        {
            t2 =t1-t2;
        }
        else if(res[i] == 'x')
        {
            t2=t1*t2;
        }
        else if(res[i] == '/')
        {
            t2=t1/t2;
        }
        ans = t2;
    }
    return ans;
}
char allocysj(int type){
    if(type == 0) return '+';
    else if(type == 1) return '-';
    else if(type == 2) return 'x';
    else return '/';
}
void bt(int k)
{
    if(k == n-1){
        int tmp = ys();
        bool flag = false;
        if(flag) cout<<'\n';
        if(tmp > _max) _max = tmp;
        if(tmp < _min) _min = tmp;
        return;
    }
    for(int i=0;i<4;i++)
    {
        if(ysj[i] > isused[i])
        {
            isused[i]++;
            res[k] = allocysj(i);
            bt(k+1);
            res[k] = 0;
            isused[i]--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>num[i];
    for(int i=0;i<4;i++) cin>>ysj[i];
    bt(0);
    cout<<_max<<'\n'<<_min<<'\n';
}