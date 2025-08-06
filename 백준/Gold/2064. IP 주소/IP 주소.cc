// Authored by: prid1306
// BOJ 2064
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;

int ParseIP(string s){
    int ret;
    int idx;
    for(int i=0;i<s.size();i++)
    {
        idx = s.find('.', i);
        if(idx == string::npos){
            idx = i - 1;
            break;
        }
        //save i ~ idx to ret
        string tmp= s.substr(i, idx - i);
        ret<<=8;ret+=stoi(tmp);
        //set i offset by idx
        i = idx;
    }
    string tmp = s.substr(idx+1, s.size() - idx-1); 
    ret<<=8;ret+=stoi(tmp);

    return ret;
}

void PrintIntToIPStyle(int num)
{
    int _num = 0;
    for(int i=4;i>0;i--){
        for(int j=1;j<=8;j++){
            if(num & 1<<(i*8 - j)) _num++;
            if(j!=8) _num<<=1;
        }
        if(i!=1) cout<<_num<<'.';
        else cout<<_num;
        _num = 0;
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        v.push_back(ParseIP(s));
    }
    int Imin=*min_element(v.begin(),v.end());
    int Imax=*max_element(v.begin(), v.end());
    int ans = Imin ^ Imax;
    int cnt = 0;
    for(int i=31;i>=0;i--){
        if(ans & (1<<i)){
            cnt = i+1;
            break;
        }
    }
    //cnt is m
    int Mask = 0;
    for(int i=0;i<32;i++){
        Mask<<=1;
        if(32 - cnt > i){
            Mask++;
        }
        
    }
    int ans2 = Mask & Imin;
    PrintIntToIPStyle(ans2);
    PrintIntToIPStyle(Mask);
}