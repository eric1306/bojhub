//Authored by: prid1306
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int t,n;
const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 10 + 5;
bool chk[MX];
int nxt[MX][10];
int c2i(char c) {return c - '0';}
void Insert(string& s)
{
    int cur = ROOT;
    for(auto c : s){
        if(nxt[cur][c2i(c)] == -1){
            nxt[cur][c2i(c)] = unused++;
            //cout<<"nxt["<<cur<<"]["<<c2i(c)<<"]: "<<nxt[cur][c2i(c)]<<'\n';
        }
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool Find(string& s)
{
    int cur = ROOT;
    for(auto c : s){
        cur = nxt[cur][c2i(c)];
    }
    for(auto c : nxt[cur]){
        if(c!=-1) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        unused = 2;
        vector<string> v;
        fill(chk,chk+MX, false);
        for(int i=0;i<MX;i++) fill(nxt[i],nxt[i]+10,-1);
        cin>>n;
        while(n--){
            string s;cin>>s;
            v.push_back(s);
            Insert(s);
        }
        bool bflag = true;
        for(auto c : v){
            if(Find(c)){
                bflag = false;
                cout<<"NO\n";
                break;
            }
        }
        if(bflag) cout<<"YES\n";
    }
}