#include <bits/stdc++.h>
using namespace std;

/*
 * 2024 Kaggle Semifinal – Problem B
 * ---------------------------------------------------------
 * "Normalization with Drift Handling"
 *
 * For each feature:
 *   - compute mean and std on training distribution
 *   - normalize evaluation dataset
 *   - clip values to [-6, 6]
 *
 * Input:
 *   N M   (training)
 *   training matrix
 *   T M   (test)
 *   test matrix
 *
 * Output:
 *   normalized & clipped values
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<double>> train(N, vector<double>(M));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> train[i][j];

    vector<double> mean(M, 0), stdv(M, 0);

    for(int j=0;j<M;j++){
        for(int i=0;i<N;i++)
            mean[j] += train[i][j];
        mean[j] /= N;

        for(int i=0;i<N;i++)
            stdv[j] += (train[i][j] - mean[j]) * (train[i][j] - mean[j]);
        stdv[j] = sqrt(stdv[j]/N);
        if(stdv[j] < 1e-12) stdv[j] = 1e-12;
    }

    int T;
    cin >> T;
    vector<vector<double>> test(T, vector<double>(M));
    for(int i=0;i<T;i++)
        for(int j=0;j<M;j++)
            cin >> test[i][j];

    for(int i=0;i<T;i++){
        for(int j=0;j<M;j++){
            double z = (test[i][j] - mean[j]) / stdv[j];
            if(z < -6) z = -6;
            if(z > 6) z = 6;
            cout << fixed << setprecision(6) << z;
            if(j+1<M) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
