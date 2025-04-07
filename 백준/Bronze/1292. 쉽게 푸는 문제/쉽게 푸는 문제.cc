//Authored by: prid1306
#include <iostream>
using namespace std;
int arr[1000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    int cnt = 1,allcnt = 0;
    while(allcnt < 1000)
    {
        int tmp = allcnt;
        for(int i=tmp;i<tmp+cnt;i++)
        {
            if(i>= 1000) break;

            arr[i] = cnt;
            allcnt++;
        }
        cnt++;
    }
    int ans = 0;
    for(int i=a-1;i<b;i++)
    {
        ans+=arr[i];
    }
    cout<<ans;
}