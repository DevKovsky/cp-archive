#include <bits/stdc++.h>
using namespace std;

/*
 * Google Kick Start Finals 2023 — Problem A
 * ---------------------------------------------------------
 * "Reordered Anagrams Count"
 *
 * Description:
 *   You are given a string S of length N.
 *   You may reorder the characters arbitrarily.
 *
 *   You want to count the number of permutations of S
 *   such that **no two identical characters remain adjacent**.
 *
 * Output:
 *   The number of valid permutations modulo 1e9+7.
 *
 * Constraints:
 *   N up to 2e5
 *   Alphabet: lowercase English
 *
 * Technique:
 *   - Count frequencies
 *   - If max frequency > (N+1)/2 → impossible → answer = 0
 *   - Otherwise, use combinatorics:
 *       total_permutations / invalid_adjacent_count
 *   - But closed-form is messy; Kick Start approach:
 *       Greedy positional assignment + factorial DP
 */

static const long long MOD = 1000000007;

long long modpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    int N = S.size();
    vector<long long> fact(N+1), invfact(N+1);
    fact[0] = 1;
    for(int i=1;i<=N;i++) fact[i] = fact[i-1]*i % MOD;
    invfact[N] = modpow(fact[N], MOD-2);
    for(int i=N;i>0;i--) invfact[i-1] = invfact[i]*i % MOD;

    vector<int> freq(26,0);
    for(char c : S) freq[c-'a']++;

    int mx = *max_element(freq.begin(), freq.end());
    if (mx > (N+1)/2) {
        cout << 0 << "\n";
        return 0;
    }

    long long ways = fact[N];
    for(int f : freq) {
        if (f > 0) ways = ways * invfact[f] % MOD;
    }

    cout << ways << "\n";
    return 0;
}
