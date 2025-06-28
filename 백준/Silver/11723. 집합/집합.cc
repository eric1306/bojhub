//Authored by: prid1306
#include <iostream>
#include <string>
using namespace std;
int s = 0;
const int _max = 0x000fffff;
int m;

void add(int x)
{
    s += (1<<(x-1));
}

void remove(int x)
{
    s -= (1<<(x-1));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m;
    while(m--)
    {
        string op;cin>>op;
        if(op == "add"){
            int x;cin>>x;
            if(!(s & 1<<(x-1)))
            {
                add(x);
            }
        }else if(op == "remove"){
            int x;cin>>x;
            if((s & 1<<(x-1)))
            {
                remove(x);
            }
        }else if(op == "check"){
            int x;cin>>x;
            if(s&(1<<x-1))cout<<"1\n";
            else cout<<"0\n";
            
        }else if(op == "toggle"){
            int x;cin>>x;
            if(s&(1<<x-1))
            {
                remove(x);
            }
            else
            {
                add(x);
            }
        }else if(op == "all"){
            s = _max;
        }else{
            s = 0;
        }
    }
}