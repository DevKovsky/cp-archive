#include <bits/stdc++.h>
using namespace std;

/*
 * Kick Start Finals 2024 – Problem D
 * "Automaton DP with Matrix Exponentiation"
 *
 * State count = S
 * Transition matrix T (S×S)
 * Given steps K, compute number of paths.
 *
 * Classic matrix exponentiation.
 */

const long long MOD = 1'000'000'007;

vector<vector<long long>> mul(const vector<vector<long long>>& A,
                              const vector<vector<long long>>& B){
    int n=A.size();
    vector<vector<long long>> R(n, vector<long long>(n,0));
    for(int i=0;i<n;i++)
        for(int k=0;k<n;k++)
            for(int j=0;j<n;j++)
                R[i][j]=(R[i][j]+A[i][k]*B[k][j])%MOD;
    return R;
}

vector<vector<long long>> mpow(vector<vector<long long>> base, long long e){
    int n=base.size();
    vector<vector<long long>> R(n, vector<long long>(n,0));
    for(int i=0;i<n;i++) R[i][i]=1;

    while(e){
        if(e&1) R=mul(R, base);
        base=mul(base, base);
        e>>=1;
    }
    return R;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S; long long K;
    cin >> S >> K;

    vector<vector<long long>> T(S, vector<long long>(S));
    for(int i=0;i<S;i++)
        for(int j=0;j<S;j++)
            cin >> T[i][j];

    auto R = mpow(T,K);

    long long ans=0;
    for(int i=0;i<S;i++)
        ans = (ans + R[0][i])%MOD;

    cout << ans << "\n";
}
