#include <bits/stdc++.h>
using namespace std;

/*
 * 2024 Kaggle Semifinal – Problem C
 * ---------------------------------------------------------
 * "Dual-Budget Feature Selection"
 *
 * Each feature i has:
 *   - compute_cost[i]
 *   - memory_cost[i]
 *   - score[i]
 *
 * Budgets:
 *   - C (compute)
 *   - M (memory)
 *
 * Goal:
 *   Maximize total score under both budgets.
 *
 * Constraints:
 *   N ≤ 2000
 *   C,M ≤ 5000
 *
 * DP[i][c][m] = max score using first i features
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C, M;
    cin >> N >> C >> M;

    vector<int> cc(N), mc(N), s(N);
    for(int i=0;i<N;i++)
        cin >> cc[i] >> mc[i] >> s[i];

    vector<vector<int>> dp(C+1, vector<int>(M+1, 0));

    for(int i=0;i<N;i++){
        for(int c=C;c>=cc[i];c--){
            for(int m=M;m>=mc[i];m--){
                dp[c][m] = max(dp[c][m], dp[c-cc[i]][m-mc[i]] + s[i]);
            }
        }
    }

    int ans = 0;
    for(int c=0;c<=C;c++)
        for(int m=0;m<=M;m++)
            ans = max(ans, dp[c][m]);

    cout << ans << "\n";
    return 0;
}
