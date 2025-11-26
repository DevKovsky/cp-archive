/////////////////////////////////////////////////////
// A - Multi-source Dijkstra
// -------------------------------------------------
// Base nodes given, weighted graph, compute min danger distance
// (Full solution below)
/////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
// Multi-source Dijkstra (full ICPC-level)
int main(){ int N,M,K; cin>>N>>M>>K;
vector<long long> c(N+1),dist(N+1,4e18);
vector<vector<pair<int,long long>>> g(N+1);
for(int i=1;i<=N;i++) cin>>c[i];
vector<int> base(K);
for(int i=0;i<K;i++) cin>>base[i];
while(M--){int u,v; long long w; cin>>u>>v>>w; g[u].push_back({v,w}); g[v].push_back({u,w});}
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
for(int b:base){ dist[b]=c[b]; pq.push({dist[b],b}); }
while(!pq.empty()){ auto [d,u]=pq.top(); pq.pop();
if(d!=dist[u]) continue;
for(auto &nx:g[u]){ long long nd=d+nx.second+c[nx.first];
if(nd<dist[nx.first]) dist[nx.first]=nd, pq.push({nd,nx.first}); }}
for(int i=1;i<=N;i++) cout<<(dist[i]>=4e18?-1:dist[i])<<"\n";
}
