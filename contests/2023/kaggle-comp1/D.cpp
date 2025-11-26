#include <bits/stdc++.h>
using namespace std;

/*
 * Kaggle Competition 2023 — Problem D
 * ---------------------------------------------------------
 * "Correlation Matrix + Outlier Detection"
 *
 * Problem:
 *   You are given a dataset of N samples and M features.
 *
 *   1) Compute the Pearson correlation coefficient matrix
 *      between all M features.
 *
 *   2) Detect outliers:
 *      A sample is an outlier if any feature's z-score
 *      is |z| > 3.0.
 *
 * Input:
 *     N M
 *     (Then N lines of M floating-point numbers)
 *
 * Output:
 *     M x M correlation matrix (rounded to 4 decimals)
 *     Then number of outliers.
 *
 * Constraints:
 *     1 ≤ N ≤ 5000
 *     1 ≤ M ≤ 200
 */

double pearson(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    double sumx = accumulate(x.begin(), x.end(), 0.0);
    double sumy = accumulate(y.begin(), y.end(), 0.0);

    double mx = sumx / n;
    double my = sumy / n;

    double num = 0, dx = 0, dy = 0;
    for (int i = 0; i < n; i++) {
        double a = x[i] - mx;
        double b = y[i] - my;
        num += a * b;
        dx += a * a;
        dy += b * b;
    }

    return num / sqrt(dx * dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<double>> data(N, vector<double>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> data[i][j];

    // Compute per-feature mean and std
    vector<double> mean(M, 0), stdv(M, 0);

    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++)
            mean[j] += data[i][j];
        mean[j] /= N;

        for (int i = 0; i < N; i++)
            stdv[j] += (data[i][j] - mean[j]) * (data[i][j] - mean[j]);
        stdv[j] = sqrt(stdv[j] / N);
    }

    // Build correlation matrix
    vector<vector<double>> C(M, vector<double>(M, 0));

    for (int i = 0; i < M; i++)
        for (int j = i; j < M; j++) {
            vector<double> xi(N), xj(N);
            for (int k = 0; k < N; k++) {
                xi[k] = data[k][i];
                xj[k] = data[k][j];
            }
            C[i][j] = C[j][i] = pearson(xi, xj);
        }

    cout << fixed << setprecision(4);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    // Outlier detection
    int outliers = 0;
    for (int i = 0; i < N; i++) {
        bool bad = false;
        for (int j = 0; j < M; j++) {
            double z = (data[i][j] - mean[j]) / stdv[j];
            if (fabs(z) > 3.0) bad = true;
        }
        if (bad) outliers++;
    }

    cout << outliers << "\n";
    return 0;
}
