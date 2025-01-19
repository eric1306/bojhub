#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[10];
int arrs[10];
bool isused[10];

void func(int k)
{
    if(k == m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    int tmp = 0;
    for(int i=0;i<n;i++){
        // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
        //이 경우는 
        if(!isused[i] && tmp!=arrs[i]){
            isused[i] = true;
            arr[k] = arrs[i];
            tmp = arr[k];
            func(k+1);
            arr[k] = 0;
            isused[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arrs[i];
    }
    sort(arrs, arrs+n);
    func(0);
}