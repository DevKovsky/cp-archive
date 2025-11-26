#include <bits/stdc++.h>
using namespace std;

/*
 * Google Kick Start Finals 2023 — Problem B
 * ---------------------------------------------------------
 * "Minimum Circles to Cover Intervals"
 *
 * Problem:
 *   You are given N points on a line.
 *   You may place circles (intervals) of radius R anywhere.
 *   One circle covers all points x such that |x - center| <= R.
 *
 * Goal:
 *   Find the minimum number of circles required.
 *
 * Constraints:
 *   N up to 2e5
 *   Coordinates up to 1e18
 *
 * Solution:
 *   Sort points.
 *   Greedy: place circle covering as many as possible.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long R;
    cin >> N >> R;

    vector<long long> x(N);
    for (long long &v : x) cin >> v;

    sort(x.begin(), x.end());

    int ans = 0;
    int i = 0;
    while (i < N) {
        ans++;
        long long start = x[i];
        long long coverLimit = start + 2*R;

        while (i < N && x[i] <= coverLimit)
            i++;
    }

    cout << ans << "\n";
    return 0;
}
