//Authored by: prid1306
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
#define x first
#define y second
int n,st,en,ans;
pair<int,int> a[1'000'001];

void printarr()
{
    for(int i=0;i<n;i++){
        cout<<a[i].x << a[i].y<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }

    sort(a,a+n);
    //printarr();
    st = a[0].x;en = a[0].y;
    for(int i=1;i<n;i++)
    {
        if(en >= a[i].x)
        {
            if(en < a[i].y) en = a[i].y;
        }
        else
        {
            ans += en-st;
            st = a[i].x;en = a[i].y;
        }
    }
    ans+=en-st;
    cout<<ans;
}