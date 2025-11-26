#include <bits/stdc++.h>
using namespace std;

/*
 * Codeforces Grand Finals 2024 – Problem C
 * "Tree Weighted Independent Set with Penalty"
 *
 * dp[u][0] = max weight if u not taken
 * dp[u][1] = max weight if u taken
 *
 * Penalty: if two siblings are both taken, subtract P.
 */

long long P;
vector<vector<int>> G;
vector<long long> w;
vector<vector<long long>> dp;

void dfs(int u, int parent){
    dp[u][0] = 0;
    dp[u][1] = w[u];

    vector<int> ch;

    for(int v : G[u]){
        if(v==parent) continue;
        dfs(v,u);
        ch.push_back(v);
    }

    for(int v : ch){
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }

    long long best = dp[u][1];
    for(int v : ch){
        long long res = dp[v][1];
        long long penalty = 0;
        for(int s : ch){
            if(s==v) continue;
            penalty += max(dp[s][0], dp[s][1]);
        }
        best = max(best, w[u] + res + penalty - P);
    }
    dp[u][1] = best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N >> P;

    w.resize(N+1);
    for(int i=1;i<=N;i++) cin >> w[i];

    G.assign(N+1,{});
    for(int i=0;i<N-1;i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dp.assign(N+1, vector<long long>(2,0));
    dfs(1,-1);

    cout << max(dp[1][0], dp[1][1]) << "\n";
}
