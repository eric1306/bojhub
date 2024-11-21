#include <bits/stdc++.h>
using namespace std;
int arr[26]={0,};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin>>a;
    for(char i : a) arr[i-'a']++;
    for(int i : arr) cout<<i<<' ';
}