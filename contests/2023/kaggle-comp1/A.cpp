#include <bits/stdc++.h>
using namespace std;

/*
 * Kaggle Competition 2023 — Problem A
 * ---------------------------------------------------------
 * "Sliding Window Maximum Feature Extraction"
 *
 * Context:
 *   In many Kaggle competitions, especially those involving
 *   time-series or sensor data, feature extraction often
 *   includes computing sliding-window statistics such as:
 *      - max
 *      - min
 *      - rolling mean
 *      - rolling std
 *
 * Task:
 *   Given an array A of length N and window size W,
 *   compute the maximum for each sliding window.
 *
 * Input:
 *     N W
 *     A1 A2 A3 ... AN
 *
 * Output:
 *     For each i from 1 to N-W+1:
 *         print max(A[i ... i+W-1])
 *
 * Constraints:
 *   N up to 2e6 (Kaggle-scale large dataset)
 *   W up to 1e6
 *   A[i] fits in 32-bit integer
 *
 * Solution:
 *   Classic monotonic deque (O(N)).
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    deque<int> dq; // stores indices, A[dq.front()] is max

    for (int i = 0; i < N; i++) {

        // Remove indices outside window
        if (!dq.empty() && dq.front() <= i - W)
            dq.pop_front();

        // Maintain decreasing order
        while (!dq.empty() && A[dq.back()] <= A[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= W - 1)
            cout << A[dq.front()] << " ";
    }

    return 0;
}
