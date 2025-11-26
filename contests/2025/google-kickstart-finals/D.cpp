#include <bits/stdc++.h>
using namespace std;

/*
 * Kick Start 2025 – Problem D
 * "Compressed Automaton Matrix Power"
 *
 * Build automaton of K states.
 * Transition matrix T.
 * Find T^L * initial_state.
 *
 * Use fast exponentiation.
 */

static const long long MOD = 1'000'000'007;

vector<vector<long long>> mul(const vector<vector<long long>>& A,
                              const vector<vector<long long>>& B){
    int n=A.size();
    vector<vector<long long>> R(n, vector<long long>(n,0));
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            long long v=A[i][k];
            if(!v) continue;
            for(int j=0;j<n;j++){
                R[i][j]=(R[i][j]+v*B[k][j])%MOD;
            }
        }
    }
    return R;
}

vector<vector<long long>> mpow(vector<vector<long long>> A, long long e){
    int n=A.size();
    vector<vector<long long>> R(n, vector<long long>(n,0));
    for(int i=0;i<n;i++) R[i][i]=1;

    while(e){
        if(e&1) R=mul(R,A);
        A=mul(A,A);
        e>>=1;
    }
    return R;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K; long long L;
    cin >> K >> L;
    vector<vector<long long>> T(K, vector<long long>(K));
    for(int i=0;i<K;i++)
        for(int j=0;j<K;j++)
            cin >> T[i][j];

    vector<long long> init(K);
    for(int i=0;i<K;i++) cin >> init[i];

    auto R = mpow(T, L);

    vector<long long> ans(K,0);
    for(int i=0;i<K;i++)
        for(int j=0;j<K;j++)
            ans[i]=(ans[i]+R[i][j]*init[j])%MOD;

    for(long long x:ans) cout << x << " ";
    cout << "\n";
}
