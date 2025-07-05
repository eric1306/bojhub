//Authored by: prid1306
#include <iostream>
#include <string>
using namespace std;

int n,m;
long long state[10];

int bit_cnt(long long x){
    int ret = 0;
    for(int i=0;i<max(n, m);i++){
        ret += (x>>i) & 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        string name, tmp;
        cin>>name>>tmp;
        for(int j=m-1;j>=0;j--){
            state[i] = (state[i]<<1) | (tmp[j] == 'Y');
        }
    }
    pair<int,int> ans = {0, -1};
    for(int tmp = 0;tmp < (1<<n);tmp++){
        long long comb = 0;
        for(int i=0;i<n;i++){
            if((tmp & (1LL << i)) == 0)
                continue;
            comb |=state[i];
        }
        int song_num = bit_cnt(comb);
        int guitar_num = bit_cnt(tmp);
        if(ans.first < song_num)
            ans = {song_num, guitar_num};
        else if(ans.first == song_num && ans.second > guitar_num)
            ans = {song_num, guitar_num};
    }
    cout<<ans.second<<'\n';
} 