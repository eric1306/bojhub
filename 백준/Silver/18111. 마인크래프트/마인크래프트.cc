// Authored by: prid1306
#include <iostream>
#define FASTIO cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
int n,m,b;
int a[501][501];
int ans = 0xfffffff;
int ansheight = 0;

bool solve(int x) //블럭을
{
    int ret = 0,tmpb = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        if(a[i][j] - x >= 0){
            tmpb += (a[i][j] - x);
            ret += 2*(a[i][j] - x);
        }
        else{
            tmpb -= (x - a[i][j]);
            ret += (x - a[i][j]);
        }
    }
    return ret >= ans && tmpb >= b;
}

int main(){
    FASTIO;
    cin>>n>>m>>b;
    int _min = 0x7fffffff;
    int _max = -1;
    //2차원 배열의 행, 열, 여분 블록 개수를 입력받는다
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j] < _min) _min = a[i][j];
            if(a[i][j] > _max) _max = a[i][j];
        }
    }
    //_min값부터 _max값 까지의 블럭개수로 맞추는 for문을 돌린다.
    for(int i=_min; i<=_max;i++)//최대 256
    {
        int tmpsum = 0,tmpb = 0;
        for(int j=0;j<n;j++)// 500
        {
            for(int k=0;k<m;k++) //500
            {
                if(a[j][k] - i >= 0)// for문 매개변수를 i라고 하면, i보다 크거나 같은 블럭들은 2 * 연산 진행
                {
                    tmpb += a[j][k] - i;
                    tmpsum += 2 * (a[j][k] - i);
                }
                else //i보다 작은 블럭은 그냥 연산진행 이 과정에서 b는 카운팅 되어야함.
                {
                    tmpb -= i - a[j][k];
                    tmpsum += i - a[j][k];
                }
            }
        }
        if(tmpsum <= ans && tmpb + b >= 0)//for문이 다 훑어본 결과값이 기존 ans값 보다 작거나 같고, 기존 b값과의 합으로 구현 가능하다면
        {
            //ans값을 갱신
            //아니라면 스킵
            ans = tmpsum;
            ansheight = i;
        }
    }
    cout<<ans<<' '<<ansheight;
    //시간복잡도: 256 * 500 * 500 = 250'000 * 256 = 64'000'000 시간복잡도 내에 처리 가능
}