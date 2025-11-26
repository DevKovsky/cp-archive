#include <bits/stdc++.h>
using namespace std;

/*
 * Kick Start Finals 2024 – Problem C
 * "DAG Longest Path with Penalty"
 *
 * Directed acyclic graph.
 * Each edge has weight.
 * State:
 *   If using >1 incoming edges of same parity, subtract penalty P.
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    long long P;
    cin >> N >> M >> P;

    vector<vector<pair<int,int>>> G(N+1);

    for(int i=0;i<M;i++){
        int u,v,w;
        cin >> u>>v>>w;
        G[u].push_back({v,w});
    }

    vector<int> indeg(N+1,0);
    for(int i=1;i<=N;i++)
        for(auto &e:G[i]) indeg[e.first]++;

    queue<int> q;
    for(int i=1;i<=N;i++)
        if(indeg[i]==0) q.push(i);

    vector<long long> dp(N+1, -4e18);
    dp[1]=0;

    while(!q.empty()){
        int u=q.front(); q.pop();
        map<int,int> parityCount;

        for(auto &e:G[u]){
            int v=e.first;
            int w=e.second;

            parityCount[w%2]++;

            long long add = dp[u] + w;
            if(parityCount[w%2]>1) add -= P;
            dp[v] = max(dp[v], add);

            if(--indeg[v]==0) q.push(v);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}
