#include <bits/stdc++.h>
using namespace std;

/*
 * ICPC Asia 2023 – Problem D
 * ---------------------------------------
 * "Minimum Spanning Tree with Edge-Type Requirements"
 *
 * Description:
 *   N nodes, M edges.
 *   Each edge has:
 *       - weight w
 *       - type FRIEND or RIVAL
 *
 *   You must build an MST with AT LEAST X FRIEND edges included.
 *
 * Task:
 *   Output the minimum possible cost of such an MST, or -1.
 *
 * Technique:
 *   Modify Kruskal:
 *     Step 1: Try to include as many FRIEND edges as possible.
 *     Step 2: Use RIVAL edges to complete MST.
 *     Step 3: If FRIEND count < X → impossible.
 */

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n+1), r(n+1,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool merge(int a, int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

struct Edge { int u, v; long long w; bool friendEdge; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X;
    cin >> N >> M >> X;

    vector<Edge> E;
    for (int i = 0; i < M; i++) {
        int u, v; long long w;
        string t;
        cin >> u >> v >> w >> t;
        E.push_back({u, v, w, t=="FRIEND"});
    }

    // Sort FRIEND edges first, then RIVAL
    sort(E.begin(), E.end(), [](const Edge &a, const Edge &b){
        if (a.friendEdge != b.friendEdge)
            return a.friendEdge > b.friendEdge;
        return a.w < b.w;
    });

    DSU dsu(N);
    long long cost = 0;
    int usedFriend = 0;
    int edgesUsed = 0;

    for (auto &e : E) {
        if (dsu.merge(e.u, e.v)) {
            cost += e.w;
            edgesUsed++;
            if (e.friendEdge) usedFriend++;
            if (edgesUsed == N-1) break;
        }
    }

    if (edgesUsed != N-1 || usedFriend < X) {
        cout << -1 << "\n";
        return 0;
    }

    cout << cost << "\n";
    return 0;
}
