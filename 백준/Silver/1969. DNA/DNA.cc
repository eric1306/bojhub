// Authored by: prid1306
// BOJ 1969
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,m;
string DNAArray[1001];
string anstring;
int alpha[4];

int HD(string& s1, string& s2)
{
    int cnt = 0;
    for(int i=0;i<m;i++) //O(m)
    {
        if(s1[i]!=s2[i]) cnt++;
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){ //O(n)
        cin>>DNAArray[i];
    }
    //각 idx에서 가장 빈도가 높으면서, 사전순으로 가장 앞에 오는 알파벳을 s의 idx자리 알파벳으로 지정
    //시간복잡도는 n개를 m번 봐야하니 n*m + 마지막으로 선정된 s를 n개와 m번 비교해야함
    //따라서 O(nm)
    for(int i=0;i<m;i++){ //O(m)
        fill(alpha, alpha+4, 0); //O(4) constant time
        for(int j=0;j<n;j++){ //O(n);
            if(DNAArray[j][i] == 'A') alpha[0]++;
            else if(DNAArray[j][i] == 'C') alpha[1]++;
            else if(DNAArray[j][i] == 'G') alpha[2]++;
            else alpha[3]++;
        }
        int tmpmax = 0;
        char maxChar;
        for(int k=0;k<4;k++){ //O(26)
            if(alpha[k] > tmpmax){
                tmpmax = alpha[k];
                switch(k)
                {
                case 0:
                    maxChar = 'A';
                    break;
                case 1:
                    maxChar = 'C';
                    break;
                case 2:
                    maxChar = 'G';
                    break;
                case 3:
                    maxChar = 'T';
                    break;
                }
            }
        }
        anstring+=maxChar;
    } //O(nm)
    int ans = 0;
    for(int i=0;i<n;i++){ //O(n)
        ans+=HD(anstring, DNAArray[i]);
    } //O(nm)
    cout<<anstring<<'\n'<<ans;
} 