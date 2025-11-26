#include <bits/stdc++.h>
using namespace std;

/*
 * Codeforces Grand Finals 2024 – Problem A
 * "Lazy Affine Segment Tree"
 *
 * Support:
 *   1) Range apply: x -> a*x + b
 *   2) Range sum query
 */

struct Node {
    long long sum, len;
    long long a, b;  // lazy: x -> a*x + b
    Node(): sum(0), len(0), a(1), b(0) {}
};

const long long MOD = 1000000007;
vector<Node> seg;

Node mergeNode(const Node &L, const Node &R){
    Node res;
    res.sum = (L.sum + R.sum) % MOD;
    res.len = L.len + R.len;
    res.a = 1;
    res.b = 0;
    return res;
}

void applyLazy(int idx, long long A, long long B){
    seg[idx].sum = (seg[idx].sum * A % MOD + seg[idx].len * B % MOD) % MOD;
    seg[idx].a = seg[idx].a * A % MOD;
    seg[idx].b = (seg[idx].b * A % MOD + B) % MOD;
}

void push(int idx){
    if(seg[idx].a != 1 || seg[idx].b != 0){
        applyLazy(idx*2, seg[idx].a, seg[idx].b);
        applyLazy(idx*2+1, seg[idx].a, seg[idx].b);
        seg[idx].a = 1;
        seg[idx].b = 0;
    }
}

void build(int idx, int l, int r, vector<long long>& arr){
    seg[idx].len = r - l + 1;
    if(l == r){
        seg[idx].sum = arr[l] % MOD;
        return;
    }
    int mid = (l+r)/2;
    build(idx*2, l, mid, arr);
    build(idx*2+1, mid+1, r, arr);
    seg[idx] = mergeNode(seg[idx*2], seg[idx*2+1]);
}

void update(int idx, int l, int r, int ql, int qr, long long A, long long B){
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr){
        applyLazy(idx, A, B);
        return;
    }
    push(idx);
    int mid = (l+r)/2;
    update(idx*2, l, mid, ql, qr, A, B);
    update(idx*2+1, mid+1, r, ql, qr, A, B);
    seg[idx] = mergeNode(seg[idx*2], seg[idx*2+1]);
}

long long query(int idx, int l, int r, int ql, int qr){
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return seg[idx].sum;
    push(idx);
    int mid = (l+r)/2;
    return (query(idx*2, l, mid, ql, qr) + query(idx*2+1, mid+1, r, ql, qr)) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,Q;
    cin >> N >> Q;

    vector<long long> arr(N+1);
    for(int i=1;i<=N;i++) cin >> arr[i];

    seg.resize(4*N+5);
    build(1,1,N,arr);

    while(Q--){
        int type; cin >> type;
        if(type==1){
            int l,r; long long A,B;
            cin >> l >> r >> A >> B;
            update(1,1,N,l,r,A,B);
        }else{
            int l,r;
            cin >> l >> r;
            cout << query(1,1,N,l,r) << "\n";
        }
    }
}
