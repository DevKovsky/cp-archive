#include <bits/stdc++.h>
using namespace std;

/*
 * Meta Hacker Cup Round 2, 2024 – Problem A
 * "Balanced XOR Partition"
 *
 * Given array A of length N.
 * Partition A into consecutive segments such that:
 *   xor(segment_1) = xor(segment_2) = ... = xor(segment_K)
 * Maximize K.
 *
 * Idea:
 *   If total_xor == 0, we can always partition greedily whenever prefix_xor == 0.
 *   Otherwise, search for prefix_xor == total_xor.
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int N; 
        cin >> N;

        vector<long long> A(N);
        for(int i=0;i<N;i++) cin >> A[i];

        long long total = 0;
        for(long long x : A) total ^= x;

        if(total == 0){
            long long now = 0, cnt = 0;
            for(int i=0;i<N;i++){
                now ^= A[i];
                if(now == 0) cnt++, now = 0;
            }
            cout << max(1LL, cnt) << "\n";
        } else {
            long long now = 0, cnt = 0;
            for(int i=0;i<N;i++){
                now ^= A[i];
                if(now == total){
                    now = 0;
                    cnt++;
                }
            }
            cout << (cnt>=2 ? cnt : 1) << "\n";
        }
    }
}
