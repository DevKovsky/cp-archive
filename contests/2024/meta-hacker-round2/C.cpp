#include <bits/stdc++.h>
using namespace std;

/*
 * Meta Hacker Cup Round 2, 2024 – Problem C
 * "Sliding Window Job Scheduling"
 *
 * Each job has (start, end, reward).
 * You can take any number of jobs as long as
 *   no more than M jobs overlap in any window of size W.
 *
 * Use sweep line + max-heap eviction strategy.
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M, W;
    cin >> N >> M >> W;

    vector<array<long long,3>> job(N);
    for(int i=0;i<N;i++)
        cin >> job[i][0] >> job[i][1] >> job[i][2];

    sort(job.begin(), job.end(), [&](auto &a, auto &b){
        return a[1] < b[1];
    });

    priority_queue<long long> pq;
    long long sum = 0;

    for(auto &j:job){
        long long s=j[0], e=j[1], r=j[2];

        pq.push(r);
        sum += r;

        while((long long)pq.size() > M){
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << sum << "\n";
}
