// Authored by: prid1306
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
bool visited[10001];

int D(int input)
{
    int ret = (input * 2) % 10000;
    return ret;
}
int S(int input)
{
    if(input == 0) return 9999;
    else return (input - 1);
}
int L(int input)
{
    string num = to_string(input);
    while(num.length() < 4)
    {
        num = "0" + num;
    }
    auto fchar = num[0];
    for(int i=0;i<3; i++)
    {
        num[i] = num[i+1];
    }
    num[3] = fchar;
    return stoi(num);
}
int R(int input)
{
    string num = to_string(input);
    while(num.length() < 4)
    {
        num = "0" + num;
    }
    auto fchar = num[3];
    for(int i=3;i>0;i--)
    {
        num[i] = num[i-1];
    }
    num[0] = fchar;
    return stoi(num);
}


void BFS(int st, int dest)
{
    queue<pair<int, string>> q;
    q.push({st, ""});
    while(true)
    {
        auto p = q.front(); q.pop();

        if(p.first == dest){
            cout<<p.second<<'\n';
            return;
        }
        int D,S,L,R,temp;
        
        D = (p.first * 2)%10000;
        if(!visited[D])
        {
            visited[D] = true;
            q.push({D, p.second + "D"});
        }
        S = p.first - 1 < 0 ? 9999 : p.first - 1;
        if(!visited[S])
        {
            visited[S] = true;
            q.push({S, p.second + "S"});
        }
        L = (p.first % 1000)*10 + (p.first/1000);
        if(!visited[L])
        {
            visited[L] = true;
            q.push({L, p.second + "L"});
        }
        R = (p.first%10)*1000 + p.first/10;
        if(!visited[R])
        {
            visited[R] = true;
            q.push({R, p.second + "R"});
        }
    }
}
int main(){
    FASTIO;
    int t;cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        fill(visited, visited + 10000, false);
        BFS(a, b);
    }
}