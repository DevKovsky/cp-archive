#include <bits/stdc++.h>
using namespace std;

/*
 * Apple 2025 – Problem D
 * "Immutable Functional Queue"
 *
 * Support:
 *  1 push x
 *  2 pop
 *  3 snapshot -> id
 *  4 load id
 *
 * Using persistent two-stack queue.
 */

struct Node{
    long long val;
    int next;
};

vector<Node> stA, stB;
vector<pair<int,int>> snapshot; // (topA, topB)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stA.resize(1); stB.resize(1);
    snapshot.push_back({0,0});

    int Q; cin >> Q;

    int topA=0, topB=0;

    while(Q--){
        int t; cin >> t;
        if(t==1){
            long long x; cin >> x;
            stA.push_back({x, topA});
            topA = (int)stA.size()-1;
        }
        else if(t==2){
            if(topB==0){
                while(topA){
                    auto cur = stA[topA];
                    stB.push_back({cur.val, topB});
                    topB = (int)stB.size()-1;
                    topA = cur.next;
                }
            }
            if(topB){
                topB = stB[topB].next;
            }
        }
        else if(t==3){
            snapshot.push_back({topA, topB});
        }
        else{
            int id; cin >> id;
            topA = snapshot[id].first;
            topB = snapshot[id].second;
        }
    }

    cout << "OK\n";
}
