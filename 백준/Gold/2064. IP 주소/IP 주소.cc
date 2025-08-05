// Authored by: prid1306
// BOJ 2064
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;

vector<string> ParseIP(string s){
    vector<string> ret;
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
        ret.push_back(tmp);
        //set i offset by idx
        i = idx;
    }
    string tmp = s.substr(idx+1, s.size() - idx-1); 
    ret.push_back(tmp);

    return ret;
}

void PrintIntToIPStyle(int num)
{
    //31~24 23~16 15~8 7~0으로 끊기
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
    vector<int> values;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vector<string> _v = ParseIP(s);
        int tmp = 0;
        for(auto k : _v){
            tmp<<=8;
            tmp+=stoi(k);
        }
        values.push_back(tmp);
    }
    vector<int> checks;
    for(int i=0;i<values.size();i++){
        for(int j=i;j<values.size();j++){
            checks.push_back(values[i] ^ values[j]);
        }
    }
    int dummy = checks[0];
    for(auto check : checks){
        dummy = dummy | check;
    }
    int cnt = 0;
    for(int i=0;i<32;i++){
        if(dummy & 1<<i) cnt = (i + 1);
    }
    //cnt is m
    int Mask = 0;
    for(int i=0;i<32;i++){
        Mask<<=1;
        if(32 - cnt > i){
            Mask++;
        }
        
    }
    int ans = Mask & values[0];
    PrintIntToIPStyle(ans);
    PrintIntToIPStyle(Mask);
}