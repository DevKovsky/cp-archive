#include <bits/stdc++.h>
using namespace std;

/*
 * Codeforces Grand Finals 2024 – Problem D
 * "Divisible Convolution"
 *
 * For sequences A, B (1-indexed):
 *   C[k] = sum_{i | j = k} (A[i] * B[j])
 *
 * Use divisor convolution trick + sieve.
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N+1), B(N+1), C(N+1,0);
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++) cin >> B[i];

    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            C[j] += A[i] * B[j/i];
        }
    }

    for(int i=1;i<=N;i++){
        cout << C[i] << (i==N ? '\n' : ' ');
    }
}
