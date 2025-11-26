#include <bits/stdc++.h>
using namespace std;

/*
 * Meta Hacker Cup Round 2, 2024 – Problem B
 * "Tree K-Divisible Path Count"
 *
 * Count number of paths where sum(path) % K == 0.
 *
 * Classic centroid decomposition + prefix mod counting.
 */

vector<vector<pair<int,int>>> G;
vector<int> sub;
vector<int> used;
int N, K;
long long answer = 0;

int dfs_size(int u, int p){
    sub[u] = 1;
    for(auto &e:G[u]){
        int v=e.first;
        if(v==p || used[v]) continue;
        sub[u] += dfs_size(v,u);
    }
    return sub[u];
}

int find_centroid(int u, int p, int tot){
    for(auto &e:G[u]){
        int v=e.first;
        if(v!=p && !used[v] && sub[v]*2>tot)
            return find_centroid(v,u,tot);
    }
    return u;
}

void collect(int u, int p, int sum, vector<int>& vals){
    vals.push_back(sum);
    for(auto &e:G[u]){
        int v=e.first, w=e.second;
        if(v==p || used[v]) continue;
        collect(v,u,(sum+w)%K,vals);
    }
}

void solve_centroid(int c){
    used[c]=1;

    unordered_map<int,int> cnt;
    cnt[0]=1;

    for(auto &e:G[c]){
        int v=e.first, w=e.second;
        if(used[v]) continue;

        vector<int> vals;
        collect(v,c,w%K,vals);

        for(int x:vals)
            answer += cnt[(K - x)%K];

        for(int x:vals)
            cnt[x]++;
    }

    for(auto &e:G[c]){
        int v=e.first;
        if(!used[v]){
            int tot = dfs_size(v,c);
            int nc = find_centroid(v,c,tot);
            solve_centroid(nc);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    G.assign(N+1,{});
    sub.assign(N+1,0);
    used.assign(N+1,0);

    for(int i=0;i<N-1;i++){
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    int tot=dfs_size(1,-1);
    int c=find_centroid(1,-1,tot);
    solve_centroid(c);

    cout << answer << "\n";
}
