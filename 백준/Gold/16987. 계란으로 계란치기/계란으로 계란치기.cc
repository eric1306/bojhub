#include <iostream>
using namespace std;

int n;
int egg[10][2];
int break_egg;

void func(int k){
    if(k == n) /*가장 오른쪽 계란 든 경우 계란 치기 종료*/
    {
        int tmp = 0;
        for(int i=0;i<n;i++){
            if(egg[i][0] <=0) tmp++;
        }
        if(tmp > break_egg) break_egg = tmp;
        return;
    }

    for(int i = 0;i<n;++i)/*k번째 계란으로 부숴지지 않은 계란 부수기 시도*/
    {
        if(k == i) continue;
        if(egg[k][0] <= 0)
        {
            func(k+1);
            return;
        }

        if(egg[i][0] > 0)
        {
            egg[k][0] -= egg[i][1];
            egg[i][0] -= egg[k][1];
            func(k+1);
            egg[k][0] += egg[i][1];
            egg[i][0] += egg[k][1];
        }
        else if(egg[i][0] <= 0)
        {
            func(k+1);
        }
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>egg[i][0]>>egg[i][1]; //내구도, 무게
    }
    /*k번째 계란으로 부수기*/
    func(0);
    
    cout<<break_egg;
}