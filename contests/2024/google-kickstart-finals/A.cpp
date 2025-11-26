#include <bits/stdc++.h>
using namespace std;

/*
 * Google Kick Start Finals 2024 – Problem A
 * "Minimize K Segments with Threshold"
 *
 * Given array A, choose exactly K non-overlapping segments.
 * Each segment's sum must be >= X.
 * Find maximum X.
 *
 * Binary search X + DP to check feasibility.
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> A(N+1);
    for(int i=1;i<=N;i++) cin >> A[i];

    vector<long long> pref(N+1);
    for(int i=1;i<=N;i++) pref[i]=pref[i-1]+A[i];

    auto ok = [&](long long X){
        vector<long long> dp(N+1, -1e18);
        dp[0] = 0;
        int seg=0;

        for(int i=1;i<=N;i++){
            dp[i] = dp[i-1];
            for(int j=i;j>=1;j--){
                if(pref[i]-pref[j-1]>=X){
                    dp[i]=max(dp[i], dp[j-1]+1);
                    break;
                }
            }
        }
        return dp[N] >= K;
    };

    long long lo=-1e15, hi=1e15, ans=0;
    while(lo<=hi){
        long long mid=(lo+hi)/2;
        if(ok(mid)) ans=mid, lo=mid+1;
        else hi=mid-1;
    }
    cout << ans << "\n";
}
