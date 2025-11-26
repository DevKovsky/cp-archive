#include <bits/stdc++.h>
using namespace std;

/*
 * Google Kick Start 2025 – Finals, Problem A
 * "Circular Gap Minimization"
 *
 * Given N points on a circle (0 ~ 1e9), choose K cuts to minimize
 * the maximum gap between consecutive segments.
 *
 * Sort, compute gaps, binary search answer.
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int N, K; 
        cin >> N >> K;
        vector<long long> A(N);
        for(long long &x : A) cin >> x;

        sort(A.begin(), A.end());

        vector<long long> gaps;
        for(int i=1;i<N;i++) gaps.push_back(A[i]-A[i-1]);
        gaps.push_back((long long)1e9 - A.back() + A[0]);

        auto can = [&](long long mx){
            long long need=0;
            for(long long g : gaps){
                if(g > mx) need += (g-1)/mx;
            }
            return need <= K;
        };

        long long L=1, R=1e9, ans=R;
        while(L<=R){
            long long M=(L+R)/2;
            if(can(M)) ans=M, R=M-1;
            else L=M+1;
        }

        cout << ans << "\n";
    }
}
