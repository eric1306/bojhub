#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[10];
int num[10];
bool isused[10];

void backtracking(int k)
{
    if(k == m)
    {
        for(int i=0;i<m;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    int tmp = 0;
    for(int i=0;i<n;i++){
        if(!isused[i] && tmp != num[i] && arr[k-1] <= num[i])
        {
            isused[i] = 1;
            arr[k] = num[i];
            tmp = arr[k];
            backtracking(k+1);
            arr[k] = 0;
            isused[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>num[i];
    sort(num,num+n);
    backtracking(0);

}