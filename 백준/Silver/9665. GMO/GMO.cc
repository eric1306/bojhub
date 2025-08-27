#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string DNA, GENE;
    cin >> DNA >> GENE;
    int costA, costC, costG, costT;
    cin >> costA >> costC >> costG >> costT;

    auto getCost = [&](char c) {
        if (c == 'A') return costA;
        if (c == 'C') return costC;
        if (c == 'G') return costG;
        return costT; // 'T'
    };

    int N = DNA.size();
    int M = GENE.size();

    const int INF = 1e9;
    vector<int> prev(M+1, INF), cur(M+1, INF);

    // 초기 조건: DNA가 비어있을 때 (i=0)
    prev[0] = 0;
    for (int j = 1; j <= M; j++) {
        prev[j] = prev[j-1] + getCost(GENE[j-1]);
    }

    int answer = INF;

    for (int i = 1; i <= N; i++) {
        cur[0] = 0; // GENE이 비어있으면 항상 0
        for (int j = 1; j <= M; j++) {
            if (DNA[i-1] == GENE[j-1]) {
                cur[j] = prev[j-1]; // 문자가 일치하면 그대로 확장
            } else {
                cur[j] = cur[j-1] + getCost(GENE[j-1]); // 삽입
            }
        }
        answer = min(answer, cur[M]); // i번째에서 GENE 완성 가능
        swap(prev, cur);
    }

    cout << answer << "\n";
    return 0;
}