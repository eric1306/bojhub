/*
양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다. 
어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;
int arr[51] = {};
//배열에 숫자 들어오면 sorting

void temp(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void sort(int* arr, int n)
{
    
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    for(int i=0; i<n;i++)
    {
        cin >> arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]<arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    int ans = arr[0] * arr[n-1];
    cout<<ans << '\n';
}