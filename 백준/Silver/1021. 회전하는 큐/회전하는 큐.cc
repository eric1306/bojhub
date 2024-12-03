#include <iostream>
#include <deque>
using namespace std;
/*************************************
양방향 순환 큐, N개 원소 포함
N: 큐의 크기, M 뽑아내는 개수
arr: 큐에서 뽑아낼 elem이 몇번지에 있는지
사이즈가 짝수일때 경계.
1 2 3 4 5(1-0 2-1 3-2 4)
1 2 3 4(1-0 2-1 3-2 4 - 1)
***************************************/
deque<int> d;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,t,ans = 0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) d.push_back(i);
    while(m--){
        cin>>t;
        if(d.front() == t){ /* 같으면 pop 하고 마무리*/
            d.pop_front();
            continue;
        }else{
            for(int i=0;i<d.size();i++){
                if(d[i] == t){
                    if((i+1) <= (d.size()/2 + 1)){
                        while(d.front()!= t){
                            d.push_back(d.front());
                            d.pop_front();
                            ans++;
                        }
                        d.pop_front();
                    }else{
                        while(d.back()!=t){
                            d.push_front(d.back());
                            d.pop_back();
                            ans++;
                        }
                        d.push_front(d.back());
                        d.pop_back();
                        ans++;
                        d.pop_front();
                    }
                }
            }
        }
    }
    cout<<ans;
}