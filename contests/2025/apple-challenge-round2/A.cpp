#include <bits/stdc++.h>
using namespace std;

/*
 * Apple Coding Competition 2025 – Round 2, Problem A
 * "Minimum-Variance Subarray"
 *
 * Given N values, find a subarray of length >= L such that
 * its statistical variance is minimized.
 *
 * Key idea:
 *   variance = E[x^2] - (E[x])^2
 * Use prefix sums and prefix squares.
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;

    vector<long long> A(N+1);
    for(int i=1;i<=N;i++) cin >> A[i];

    vector<long long> S(N+1,0), SQ(N+1,0);
    for(int i=1;i<=N;i++){
        S[i] = S[i-1] + A[i];
        SQ[i] = SQ[i-1] + A[i]*A[i];
    }

    long double best = 1e30;

    for(int i=L;i<=N;i++){
        for(int len=L; len<=300 && len<=i; len++){ 
            long long sum = S[i] - S[i-len];
            long long sq  = SQ[i] - SQ[i-len];
            long double mean = (long double)sum / len;
            long double var = (long double)sq/len - mean*mean;
            best = min(best, var);
        }
    }

    cout << fixed << setprecision(6) << (double)best << "\n";
}
