//Authored by: prid1306
#include <iostream>
#include <string>
using namespace std;
bool IsJavaFeature(string& s)
{
    if((s[0] >= 'A' && s[0] <= 'Z') || (s[0] < 'a' || s[0] > 'z'))
        return false;

    for(int i=1;i<s.size();i++)
    {
        if(s[i] == '_')
        {
            return false;
        }
    }
    return true;
}

bool IsCPPFeature(string& s)
{
    if(s[0] < 'a' || s[0] >'z')
        return false;
    for(int i=1;i<s.size();i++)
    {
        if((s[i] >='A' && s[i] <= 'Z') || (s[i] == '_' && (i == s.size()-1 || s[i-1] == '_')))
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    bool hasJavaFeature = IsJavaFeature(s);
    bool hasCPPFeature = IsCPPFeature(s);
    
    if(!hasCPPFeature && !hasJavaFeature)
    {
        cout<<"Error!";
        return 0;
    }
    if(hasCPPFeature && !hasJavaFeature)
    {
        while(true)
        {
            int st = 0;
            auto idx = s.find('_',st);
            if(idx == string::npos) break;
            string tmp="";
            tmp = s[idx+1] - ('a' - 'A');
            s.replace(idx,2, tmp);
        }
    }
    else if(!hasCPPFeature && hasJavaFeature)
    {
        for(char a = 'A';a <='Z'; a++)
        {
            while(true)
            {
                int st = 0;
                auto idx = s.find(a,st);
                if(idx == string::npos) break;
                string tmp="_";
                tmp += s[idx] + ('a' - 'A');
                s.replace(idx,1, tmp);
            }
        }
    }
    cout<<s<<' ';

}