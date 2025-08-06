#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 11차원 크기를 저장
    vector<int> size(11);
    int total = 1;
    
    // 각 차원의 크기 입력받고 전체 크기 계산
    for(int i = 0; i < 11; i++){
        cin >> size[i];
        total *= size[i];
    }
    
    // 좌표 변환을 위한 승수 배열 계산
    vector<int> multiplier(11);
    multiplier[0] = 1;
    for(int i = 1; i < 11; i++){
        multiplier[i] = multiplier[i-1] * size[i-1];
    }
    
    // 토마토 상태와 거리 배열
    vector<int> tomato(total);
    vector<int> dist(total, -1);
    queue<int> q;
    
    // 토마토 상태 입력받고 익은 토마토를 큐에 추가
    for(int i = 0; i < total; i++){
        cin >> tomato[i];
        if(tomato[i] == 1){
            q.push(i);
            dist[i] = 0;  // 초기 익은 토마토는 0일차
        }
    }
    
    // BFS로 토마토 익히기 시뮬레이션
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        // 11차원에서 각 방향(+1, -1)으로 이동 시도
        for(int dim = 0; dim < 11; dim++){
            for(int direction = -1; direction <= 1; direction += 2){
                int next = current + direction * multiplier[dim];
                
                // 경계 검사: 해당 차원에서 범위를 벗어나는지 확인
                int current_coord = (current / multiplier[dim]) % size[dim];
                int next_coord = current_coord + direction;
                
                // 좌표가 유효 범위를 벗어나거나 이미 방문했거나 벽(-1)인 경우 건너뛰기
                if(next_coord < 0 || next_coord >= size[dim] || 
                    next < 0 || next >= total ||
                    dist[next] != -1 || tomato[next] == -1){
                    continue;
                }
                
                // 익지 않은 토마토(0)를 익히고 큐에 추가
                if(tomato[next] == 0){
                    dist[next] = dist[current] + 1;
                    q.push(next);
                }
            }
        }
    }
    
    // 결과 계산
    int max_days = 0;
    for(int i = 0; i < total; i++){
        if(tomato[i] == 0 && dist[i] == -1){
            // 익지 않은 토마토가 남아있으면 -1 출력
            cout << -1 << '\n';
            return 0;
        }
        if(tomato[i] == 0 || tomato[i] == 1){
            // 익을 수 있는 토마토 중 최대 일수 계산
            max_days = max(max_days, dist[i]);
        }
    }
    
    cout << max_days << '\n';
    return 0;
}