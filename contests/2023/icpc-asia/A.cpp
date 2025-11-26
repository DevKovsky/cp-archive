#include <bits/stdc++.h>
using namespace std;

/*
 * ICPC Asia 2023 – Problem A
 * ---------------------------------------
 * "Safe Paths from Multiple Bases"
 *
 * Description:
 *   You are given a region with N cities and M bidirectional roads.
 *   Each city i has a danger cost cost[i].
 *
 *   There are K base cities. You may start from ANY base city.
 *
 *   When traveling along an edge (u, v, w), moving from u → v adds:
 *        + w (road cost)
 *        + cost[v] (danger of entering v)
 *
 * Task:
 *   For every city, compute the minimum possible danger-cost to reach it
 *   from any base city. If a city is unreachable, print -1.
 *
 * Constraints:
 *   1 ≤ N, M ≤ 2e5
 *   1 ≤ cost[i], w ≤ 1e9
 *   1 ≤ K ≤ N
 *
 * Solution:
 *   Multi-source Dijkstra from all base cities initially.
 */

struct Edge { int to; long long w; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> cost(N + 1);
    for (int i = 1; i <= N; i++) cin >> cost[i];

    vector<int> base(K);
    for (int i = 0; i < K; i++) cin >> base[i];

    vector<vector<Edge>> g(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    const long long INF = 4e18;
    vector<long long> dist(N + 1, INF);

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    // Multi-source initialization
    for (int b : base) {
        dist[b] = cost[b];
        pq.push({dist[b], b});
    }

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;

        for (auto &e : g[u]) {
            long long nd = d + e.w + cost[e.to];
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << (dist[i] >= INF ? -1 : dist[i]) << "\n";

    return 0;
}
