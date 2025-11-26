#include <bits/stdc++.h>
using namespace std;

/*
 * ICPC Asia 2023 – Problem C
 * ---------------------------------------
 * "Team Assignment under SAME/DIFF Constraints"
 *
 * Description:
 *   N people must be assigned to Team A or Team B.
 *   M constraints are of two types:
 *      SAME u v   → u and v must be on the same team.
 *      DIFF u v   → u and v must be on different teams.
 *
 * Task:
 *   Determine whether such an assignment is possible.
 *
 * Technique:
 *   Convert to 2-SAT:
 *     Let variable Xi = (i on Team A).
 *     Xi true  <=> i in A
 *     Xi false <=> i in B
 *
 *   SAME(u, v):
 *     (Xu → Xv), (Xv → Xu)
 *     (!Xu → !Xv), (!Xv → !Xu)
 *
 *   DIFF(u, v):
 *     (Xu → !Xv), (!Xu → Xv)
 *     (Xv → !Xu), (!Xv → Xu)
 *
 *   Use SCC (Kosaraju or Tarjan).
 */

struct SCC {
    int N;
    vector<vector<int>> g, rg;
    vector<int> order, comp, used;

    SCC(int n): N(n), g(n), rg(n), comp(n, -1), used(n,0) {}

    void addEdge(int u, int v) {
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    void dfs1(int v) {
        used[v] = 1;
        for (int nx : g[v])
            if (!used[nx]) dfs1(nx);
        order.push_back(v);
    }

    void dfs2(int v, int c) {
        comp[v] = c;
        for (int nx : rg[v])
            if (comp[nx] == -1) dfs2(nx, c);
    }

    void solve() {
        for (int i = 0; i < N; i++)
            if (!used[i]) dfs1(i);
        reverse(order.begin(), order.end());
        int c = 0;
        for (int v : order)
            if (comp[v] == -1) dfs2(v, c++);
    }
};

int varA(int i) { return 2*(i-1); }
int varB(int i) { return 2*(i-1)^1; }
int inv(int x) { return x^1; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    SCC scc(2*N);

    for (int i = 0; i < M; i++) {
        string type;
        int u, v;
        cin >> type >> u >> v;

        int uA = varA(u), uB = varB(u);
        int vA = varA(v), vB = varB(v);

        if (type == "SAME") {
            scc.addEdge(uA, vA);
            scc.addEdge(vA, uA);
            scc.addEdge(uB, vB);
            scc.addEdge(vB, uB);
        } else {
            scc.addEdge(uA, vB);
            scc.addEdge(vB, uA);
            scc.addEdge(uB, vA);
            scc.addEdge(vA, uB);
        }
    }

    scc.solve();

    for (int i = 1; i <= N; i++) {
        if (scc.comp[varA(i)] == scc.comp[varB(i)]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
