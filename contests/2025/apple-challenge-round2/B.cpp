#include <bits/stdc++.h>
using namespace std;

/*
 * Apple 2025 – Problem B
 * "Swift-like String Tokenizer Minimization"
 *
 * Split string S into tokens.
 * Transition cost depends on token type changes.
 *
 * DP over states (letter, digit, symbol).
 */

int typeOf(char c){
    if(isalpha(c)) return 0;
    if(isdigit(c)) return 1;
    return 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int N = S.size();

    const long long INF = 4e18;
    vector<vector<long long>> dp(N, vector<long long>(3, INF));

    int t0 = typeOf(S[0]);
    dp[0][t0]=1;

    for(int i=1;i<N;i++){
        int t = typeOf(S[i]);
        for(int prev=0;prev<3;prev++){
            long long base = dp[i-1][prev];
            if(base>=INF) continue;

            if(prev==t) dp[i][t] = min(dp[i][t], base);
            else dp[i][t] = min(dp[i][t], base+1);
        }
    }

    cout << *min_element(dp[N-1].begin(), dp[N-1].end()) << "\n";
}
