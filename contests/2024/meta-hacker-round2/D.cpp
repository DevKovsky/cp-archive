#include <bits/stdc++.h>
using namespace std;

/*
 * Meta Hacker Cup Round 2, 2024 – Problem D
 * "Linear Recurrence with Large Step"
 *
 * Given first L terms and need F-th term modulo MOD.
 * Use Berlekamp–Massey to detect recurrence, then exponentiate.
 */

const long long MOD = 1'000'000'007;

vector<long long> berlekamp_massey(const vector<long long>& s){
    vector<long long> C(1,1), B(1,1);
    long long L=0, m=1, b=1;

    for(int n=0;n<(int)s.size();n++){
        long long d=0;
        for(int i=0;i<=L;i++)
            d=(d+C[i]*s[n-i])%MOD;
        if(d==0) { m++; continue; }

        vector<long long> T=C;
        long long coef=d*1LL * pow(b, MOD-2)%MOD;
        C.resize(max(C.size(), B.size()+m));
        for(int i=0;i<(int)B.size();i++)
            C[i+m]=(C[i+m] - coef*B[i])%MOD;

        if(2*L <= n){
            L=n+1-L;
            B=T;
            b=d;
            m=1;
        } else m++;
    }

    for(auto &x:C) if(x<0) x+=MOD;
    return C;
}

vector<long long> combine(vector<long long>& A, vector<long long>& B, vector<long long>& rec){
    int k=rec.size()-1;
    vector<long long> R(2*k+1,0);

    for(int i=0;i<=k;i++)
        for(int j=0;j<=k;j++)
            R[i+j]=(R[i+j]+A[i]*B[j])%MOD;

    for(int i=2*k;i>k;i--)
        for(int j=1;j<=k;j++)
            R[i-j]=(R[i-j]+R[i]*rec[j])%MOD;

    R.resize(k+1);
    return R;
}

long long linear_kth(vector<long long> &init, vector<long long> &rec, long long n){
    int k = rec.size()-1;
    if(n < (int)init.size()) return init[n];

    vector<long long> pol(k+1), e(k+1);
    pol[0]=1;
    e[1]=1;

    n++;
    while(n){
        if(n&1) pol=combine(pol,e,rec);
        e=combine(e,e,rec);
        n>>=1;
    }

    long long ans=0;
    for(int i=0;i<k;i++)
        ans=(ans+pol[i]*init[i])%MOD;

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    long long F;
    cin >> L >> F;

    vector<long long> seq(L);
    for(int i=0;i<L;i++) cin >> seq[i];

    auto rec = berlekamp_masse_
