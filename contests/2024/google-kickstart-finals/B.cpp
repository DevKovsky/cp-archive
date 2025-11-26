#include <bits/stdc++.h>
using namespace std;

/*
 * Kick Start Finals 2024 – Problem B
 * "Minimum Blockers"
 *
 * Given N intervals, place blockers on a line.
 * One blocker removes all intervals covering that point.
 * Find min blockers to remove all intervals.
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<long long,long long>> seg(N);
    for(int i=0;i<N;i++) cin >> seg[i].first >> seg[i].second;

    sort(seg.begin(), seg.end(), [](auto &a, auto &b){
        return a.second<b.second;
    });

    long long last=-4e18;
    int ans=0;

    for(auto &s:seg){
        if(s.first > last){
            last = s.second;
            ans++;
        }
    }

    cout << ans << "\n";
}
