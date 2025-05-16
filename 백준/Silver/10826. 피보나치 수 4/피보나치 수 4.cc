//Authored by: prid1306
#include <iostream>
#include <string>
using namespace std;
using ull = unsigned long long int;

string Add(string a, string b)
{
    string result = a;
    for(int i=0;i<b.size();i++)
    {
        //cout<<(int)(result[i] - '0')<<' '<<(int)(b[i] - '0')<<'\n';
        if((int)(result[i] - '0') + (int)(b[i] - '0') >= 10)
        {
            result[i] = (char)((int)(result[i] - '0') + (int)(b[i] - '0') - 10 + '0');
            if(a.size() == b.size() && i==a.size()-1)
            {
                result.append("1");
            }
            else
            {
                result[i+1] +=1;
            }
        }
        else
        {
            result[i] = (char)((int)(result[i] - '0') + (int)(b[i] - '0') + '0');
        }
        //cout<<"result["<<i<<"]: "<<result[i]<<'\n';
    }
    return result;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string a[10001];
    a[0] = "0";a[1] = "1";
    for(int i=2;i<=n;i++)
    {
        a[i] = Add(a[i-1],a[i-2]);
        //cout<<i<<"번째 수: "<<a[i]<<'\n';
    }

    for(int i=a[n].size()-1;i>=0;i--)
    {
        cout<<a[n][i];
    }
}