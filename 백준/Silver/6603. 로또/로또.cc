#include <iostream>
using namespace std;

#define MAX 13

int asize;
int arr[6];
int num[MAX];
bool isused[MAX];

void func(int k)
{
    if(k == 6)
    {
        for(int i=0;i<6;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0;i<asize;i++)
    {
        if(!isused[i] && arr[k-1] <= num[i])
        {
            isused[i] = 1;
            arr[k] = num[i];
            func(k+1);
            arr[k] = 0;
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    while(true)
    {
        cin>>asize;
        if(!asize) return 0;

        for(int i=0;i<asize;++i) 
            cin>>num[i];
        
        func(0);
        cout<<'\n';
        fill(num,num+MAX,0);
        fill(arr,arr+6,0);
        fill(isused,isused+MAX,0);
    }
}