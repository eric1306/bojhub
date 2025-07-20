// Authored by: prid1306
// BOJ 9536
#include <iostream>
#include <string>
#include <map>
using namespace std;
string sounds;
string animalSound;
map<string,string> m; //key : 소리, value: 동물
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;cin>>tc;
    getline(cin,sounds);
    while(tc--)
    {
        //init
        m.clear();
        string ans;
        //parsing
        getline(cin,sounds);
        while(true)
        {
            getline(cin,animalSound);
            int idx = animalSound.find("goes");
            if(idx == string::npos)
                break;
            string animal,sound;
            for(int i=0;i<idx-1;i++){
                animal+=animalSound[i];
            }
            for(int i=idx+5;i<animalSound.length();i++){
                sound+=animalSound[i];
            }
            m[sound] = animal;
        }
        for(int i=0;i<sounds.length();i++){
            if(sounds.find(" ", i) == string::npos)
            {
                string lastSound;
                for(int j=i;j<sounds.length();j++){
                    lastSound+=sounds[j];
                }
                if(m.find(lastSound) == m.end())
                {
                    ans+=lastSound;
                }
                break;
            }
            int idx = sounds.find(" ", i);
            string pSound;
            for(int j=i;j<idx;j++){
                pSound+=sounds[j];
            }
            if(m.find(pSound) == m.end())
            {
                ans+=pSound;
                ans+=" ";
            }
            i=idx;
        }
        cout<<ans<<'\n';
    }
}