#include <bits/stdc++.h>
using namespace std;

/*
 * Codeforces Grand Finals 2024 – Problem B
 * "Directed Graph Min Cycle with Parity Constraint"
 *
 * Each edge has a parity (0/1).
 * Find the minimum cycle whose total parity == 1.
 */

struct Edge { int to; int w; };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    vector<vector<Edge>> G(N+1);

    for(int i=0;i<M;i++){
        int u,v,w;
        cin >> u >> v >> w; // w = 0 or 1
        G[u].push_back({v,w});
    }

    const long long INF = 4e18;
    long long ans = INF;

    for(int start=1; start<=N; start++){
        vector<vector<long long>> dist(N+1, vector<long long>(2, INF));
        dist[start][0] = 0;

        deque<pair<int,int>> dq;
        dq.push_back({start,0});

        while(!dq.empty()){
            auto [u,p] = dq.front();
            dq.pop_front();

            for(auto &e : G[u]){
                int np = (p + e.w) % 2;
                long long nd = dist[u][p] + 1;
                if(nd < dist[e.to][np]){
                    dist[e.to][np] = nd;
                    dq.push_back({e.to,np});
                }
            }
        }

        if(dist[start][1] < ans) ans = dist[start][1];
    }

    cout << (ans>=INF ? -1 : ans) << "\n";
}
