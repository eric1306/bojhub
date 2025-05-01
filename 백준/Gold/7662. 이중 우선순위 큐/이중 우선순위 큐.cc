//Authored by: prid1306
#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        char input1;
        int k,input2;
        multiset<int> s;
        cin>>k;
        while(k--)
        {
            cin>>input1>>input2;
            if(input1 == 'I')
            {
                s.insert(input2);
            }
            else//D
            {
                if(!s.size()) continue;
                if(input2 == 1)
                {
                    auto it = s.end();
                    it--;
                    s.erase(it);
                }
                else
                {
                    s.erase(s.begin());
                }
            }
        }

        if(!s.size()) 
            cout<<"EMPTY\n";
        else{
            auto it = s.end();
            it--;        
            cout<<*it<<' '<<*s.begin()<<'\n';
        }
    }
} 