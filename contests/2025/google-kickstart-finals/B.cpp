#include <bits/stdc++.h>
using namespace std;

/*
 * Kick Start 2025 – Problem B
 * "Forbidden-State Graph Walk"
 *
 * Directed graph. Count paths of exact length L
 * avoiding forbidden bitmask states.
 *
 * DP with adjacency compression.
 */

static const long long MOD = 1'000'000'007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, L;
    cin >> N >> M >> L;

    vector<vector<int>> G(N);
    for(int i=0;i<M;i++){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
    }

    vector<int> forb(N);
    for(int i=0;i<N;i++) cin >> forb[i];

    vector<long long> dp(N,0), ndp(N,0);
    dp[0]=1;

    while(L--){
        fill(ndp.begin(), ndp.end(), 0);
        for(int u=0;u<N;u++){
            if(dp[u]==0 || forb[u]) continue;
            for(int v:G[u]){
                if(!forb[v]) ndp[v]=(ndp[v]+dp[u])%MOD;
            }
        }
        dp.swap(ndp);
    }

    long long ans=0;
    for(int i=0;i<N;i++) if(!forb[i]) ans=(ans+dp[i])%MOD;
    cout << ans << "\n";
}
