#include <iostream>
using namespace std;

int n,w,L;
int weight[1001];
int DistTruck[1001];
bool isTruckUpBridge[1001];
int bridge_weight;
int ans_time;
int leftTruckNum;
int RightTruckNum;
int CurrentNextTruck;
int PropTruck;

void MoveTruck()
{
    for(int i=PropTruck;i<CurrentNextTruck;i++)
    {
        if(isTruckUpBridge[i])
        {
            DistTruck[i]++;
            if(DistTruck[i] == w+1)//다리 밖으로 나가게됨
            {
                isTruckUpBridge[i] = false;
                bridge_weight -=weight[i];
                leftTruckNum++;
                RightTruckNum--;
                PropTruck++;
            }
        }
    }
}

void BF(){
    while(leftTruckNum < n)
    {
        MoveTruck();//트럭들 앞으로 밀기
        if(CurrentNextTruck < n)
        {
            if(bridge_weight + weight[CurrentNextTruck] <= L) /*다리에 새 트럭 올릴 수 있다면*/
            {
                bridge_weight+=weight[CurrentNextTruck];
                isTruckUpBridge[CurrentNextTruck] = true;
                ++DistTruck[CurrentNextTruck++];
            }
        }
        ans_time++;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>w>>L;
    for(int i=0;i<n;i++) cin>>weight[i];
    RightTruckNum = n;
    BF();
    cout<<ans_time;

}