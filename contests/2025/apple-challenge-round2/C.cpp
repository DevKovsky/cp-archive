#include <bits/stdc++.h>
using namespace std;

/*
 * Apple 2025 – Problem C
 * "Battery-Constrained Task Scheduling"
 *
 * N tasks. Each task has:
 *    duration d, battery cost b, reward r
 *
 * Total battery capacity B.
 * Maximize total reward under:
 *    sum(durations of selected tasks) <= T
 *    sum(battery) <= B
 *
 * Use 2D knapsack DP.
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T, B;
    cin >> N >> T >> B;

    vector<int> d(N), bc(N), r(N);
    for(int i=0;i<N;i++) cin >> d[i] >> bc[i] >> r[i];

    vector<vector<int>> dp(T+1, vector<int>(B+1,0));

    for(int i=0;i<N;i++){
        for(int td=T; td>=d[i]; td--){
            for(int bb=B; bb>=bc[i]; bb--){
                dp[td][bb] = max(dp[td][bb], dp[td-d[i]][bb-bc[i]] + r[i]);
            }
        }
    }

    int best=0;
    for(int td=0;td<=T;td++)
        for(int bb=0;bb<=B;bb++)
            best = max(best, dp[td][bb]);

    cout << best << "\n";
}
