#include <bits/stdc++.h>
using namespace std;

/*
 * Kick Start 2025 – Problem C
 * "Sliding Window Median of Medians"
 *
 * Window size W, step S.
 * For each window, compute median.
 * Then compute final median of all these medians.
 *
 * Use two multisets to maintain window median.
 */

multiset<long long> lowSet, highSet;

void rebalance(){
    while(lowSet.size() > highSet.size()+1){
        highSet.insert(*lowSet.rbegin());
        auto it = lowSet.end(); it--;
        lowSet.erase(it);
    }
    while(highSet.size() > lowSet.size()){
        lowSet.insert(*highSet.begin());
        highSet.erase(highSet.begin());
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W, S;
    cin >> N >> W >> S;

    vector<long long> A(N);
    for(long long &x:A) cin >> x;

    vector<long long> meds;

    auto addVal=[&](long long x){
        if(lowSet.empty() || x <= *lowSet.rbegin()) lowSet.insert(x);
        else highSet.insert(x);
        rebalance();
    };

    auto removeVal=[&](long long x){
        auto it = lowSet.find(x);
        if(it!=lowSet.end()) lowSet.erase(it);
        else{
            it = highSet.find(x);
            highSet.erase(it);
        }
        rebalance();
    };

    for(int i=0;i<W;i++) addVal(A[i]);
    meds.push_back(*lowSet.rbegin());

    for(int i=W;i<N;i+=S){
        for(int k=0;k<S && i+k<N;k++){
            removeVal(A[i+k-W]);
            addVal(A[i+k]);
        }
        meds.push_back(*lowSet.rbegin());
    }

    sort(meds.begin(), meds.end());
    cout << meds[meds.size()/2] << "\n";
}
