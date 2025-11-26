#include <bits/stdc++.h>
using namespace std;

/*
 * Kaggle Competition 2023 — Problem C
 * ---------------------------------------------------------
 * "Feature Engineering Sequential Optimization"
 *
 * Context:
 *   In Kaggle competitions, feature generation often imposes
 *   a computation-time or memory constraint. You cannot include
 *   all features, so you select an optimal subset.
 *
 * Problem:
 *   You are given N candidate features. Each feature i has:
 *       cost[i]   — time required to compute this feature
 *       score[i]  — contribution to model performance
 *
 *   You have a total computation budget B.
 *
 * Task:
 *   Choose a subset of features maximizing total score,
 *   such that total cost ≤ B.
 *
 *   (Equivalent to 0/1 knapsack.)
 *
 * Constraints:
 *   N ≤ 2000
 *   B ≤ 200000
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, B;
    cin >> N >> B;

    vector<int> cost(N), score(N);
    for (int i = 0; i < N; i++)
        cin >> cost[i] >> score[i];

    vector<int> dp(B + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int c = B; c >= cost[i]; c--) {
            dp[c] = max(dp[c], dp[c - cost[i]] + score[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}
