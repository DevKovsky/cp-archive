/////////////////////////////////////////////////////
// B - DAG Longest Path
// -------------------------------------------------
// Scheduling with prerequisites to compute minimum finish time.
// (Full solution below)
/////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
int main(){ int N,M; cin>>N>>M;
vector<long long> t(N+1),dp(N+1,0);
vector<vector<int>> g(N+1);
vector<int> indeg(N+1,0);
for(int i=1;i<=N;i++) cin>>t[i];
while(M--){int u,v;cin>>u>>v;g[u].push_back(v); indeg[v]++;}
queue<int> q;
for(int i=1;i<=N;i++) if(indeg[i]==0){ q.push(i); dp[i]=t[i]; }
long long ans=0;
while(!q.empty()){ int u=q.front();q.pop(); ans=max(ans,dp[u]);
for(int v:g[u]){ dp[v]=max(dp[v],dp[u]+t[v]); if(--indeg[v]==0) q.push(v);}}
cout<<ans;
}
