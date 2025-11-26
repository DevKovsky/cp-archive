#include <bits/stdc++.h>
using namespace std;

/*
 * 2024 Kaggle Semifinal – Problem A
 * ---------------------------------------------------------
 * "Sparse High-Dimensional Feature Aggregation"
 *
 * You are given a very large dataset with sparse feature vectors.
 * Each sample contains K non-zero (index, value) pairs among D features.
 *
 * Task:
 *   For N samples, compute for each feature:
 *      - sum
 *      - max
 *      - count of non-zero values
 *
 * Input:
 *   N D
 *   For each of N samples:
 *       K idx1 val1 idx2 val2 ... idxK valK
 *
 * Output:
 *   For each feature j in [1..D]:
 *       sum_j max_j count_j
 *
 * Constraints:
 *   N ≤ 300,000
 *   D ≤ 200,000
 *   K ≤ 300
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;

    vector<long long> sumF(D+1, 0);
    vector<long long> maxF(D+1, LLONG_MIN);
    vector<int> cntF(D+1, 0);

    for(int i=0;i<N;i++) {
        int K;
        cin >> K;
        for(int j=0;j<K;j++){
            int idx;
            long long v;
            cin >> idx >> v;
            sumF[idx] += v;
            maxF[idx] = max(maxF[idx], v);
            cntF[idx]++;
        }
    }

    for(int i=1;i<=D;i++) {
        long long mx = (maxF[i] == LLONG_MIN ? 0 : maxF[i]);
        cout << sumF[i] << " " << mx << " " << cntF[i] << "\n";
    }
    return 0;
}
