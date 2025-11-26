#include <bits/stdc++.h>
using namespace std;

/*
 * ICPC Asia 2023 – Problem B
 * ---------------------------------------
 * "Parallel Task Scheduling in a DAG"
 *
 * Description:
 *   There are N tasks and M prerequisite relations.
 *   Completing task i requires time T[i].
 *
 *   If u → v is a prerequisite, then v cannot start until u finishes.
 *   Multiple tasks can run in parallel as long as dependencies are satisfied.
 *
 * Task:
 *   Determine the minimum time required to complete ALL tasks.
 *
 * Solution:
 *   This is the longest-path DP on a DAG (topological order).
 *   dp[v] = maximum finishing time of v.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> T(N + 1);
    for (int i = 1; i <= N; i++) cin >> T[i];

    vector<vector<int>> g(N + 1);
    vector<int> indeg(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    vector<long long> dp(N + 1, 0);

    // Start with all nodes with indegree 0
    for (int i = 1; i <= N; i++) {
        if (indeg[i] == 0) {
            q.push(i);
            dp[i] = T[i];
        }
    }

    long long ans = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans = max(ans, dp[u]);

        for (int v : g[u]) {
            dp[v] = max(dp[v], dp[u] + T[v]);
            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    cout << ans << "\n";
    return 0;
}
