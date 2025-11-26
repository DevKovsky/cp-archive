#include <bits/stdc++.h>
using namespace std;

/*
 * 2024 Kaggle Semifinal – Problem D
 * ---------------------------------------------------------
 * "Correlation Matrix + Robust Outlier Flagging"
 *
 * 1) Compute Pearson correlation between features.
 * 2) Flag rows as outliers if any feature |z| > 4.0
 *
 * N ≤ 6000
 * M ≤ 250
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    vector<vector<double>> X(N, vector<double>(M));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> X[i][j];

    vector<double> mean(M,0), stdv(M,0);
    for(int j=0;j<M;j++){
        for(int i=0;i<N;i++) mean[j]+=X[i][j];
        mean[j]/=N;

        for(int i=0;i<N;i++)
            stdv[j]+=(X[i][j]-mean[j])*(X[i][j]-mean[j]);
        stdv[j] = sqrt(stdv[j]/N);
        if(stdv[j] < 1e-12) stdv[j] = 1e-12;
    }

    cout << fixed << setprecision(4);

    for(int a=0;a<M;a++){
        for(int b=0;b<M;b++){
            double num=0,da=0,db=0;
            for(int i=0;i<N;i++){
                double A = X[i][a] - mean[a];
                double B = X[i][b] - mean[b];
                num += A*B;
                da += A*A;
                db += B*B;
            }
            double corr = num / sqrt(da*db);
            cout << corr;
            if(b+1<M) cout << " ";
        }
        cout << "\n";
    }

    int out = 0;
    for(int i=0;i<N;i++){
        bool flag=false;
        for(int j=0;j<M;j++){
            double z = (X[i][j]-mean[j])/stdv[j];
            if(fabs(z) > 4.0) flag=true;
        }
        if(flag) out++;
    }
    cout << out << "\n";

    return 0;
}
