//Authored by prid1306
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[1001];
vector<pair<int, int>> adj_r[1001];

vector<int> D(int st, const vector<pair<int, int>> adj[], int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[st] = 0;
    pq.push({ 0, st });

    while (!pq.empty()) {
        auto cur = pq.top();pq.pop();
        if (dist[cur.Y] != cur.X) continue;
        for (auto nxt : adj[cur.Y]) {
            if (dist[nxt.X] > dist[cur.Y] + nxt.Y) {
                dist[nxt.X] = dist[cur.Y] + nxt.Y;
                pq.push({ dist[nxt.X], nxt.X });
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x;
    cin>>n>>m>>x;

    while(m--) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({ b, cost });
        adj_r[b].push_back({ a, cost }); 
    }
    vector<int> x_dist = D(x, adj, n);

    vector<int> dist_x = D(x, adj_r, n);

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int round_trip = dist_x[i] + x_dist[i];
        answer = max(answer, round_trip);
    }

    cout << answer << '\n';

    return 0;
}
