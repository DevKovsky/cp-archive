#include <bits/stdc++.h>
using namespace std;

/*
 * Kaggle Competition 2023 — Problem B
 * ---------------------------------------------------------
 * "Data Normalization Pipeline Simulation"
 *
 * Context:
 *   Before feeding data into ML models, Kaggle pipelines
 *   apply normalization/standardization such as:
 *      - StandardScaler: (x - mean) / std
 *      - MinMaxScaler:   (x - min) / (max - min)
 *      - RobustScaler:   (x - median) / IQR
 *
 * Task:
 *   Given N data points and a scaler type, output the
 *   transformed result.
 *
 * Input:
 *    scalerType (STANDARD | MINMAX | ROBUST)
 *    N
 *    x1 x2 ... xN
 *
 * Output:
 *    transformed values with 6 decimal precision.
 *
 * Constraints:
 *   N up to 3e6 (large data typical for Kaggle)
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string scaler;
    cin >> scaler;

    int N;
    cin >> N;

    vector<double> x(N);
    for (int i = 0; i < N; i++)
        cin >> x[i];

    cout << fixed << setprecision(6);

    if (scaler == "STANDARD") {
        double mean = accumulate(x.begin(), x.end(), 0.0) / N;

        double var = 0;
        for (double v : x) var += (v - mean) * (v - mean);
        var /= N;
        double stdv = sqrt(var);

        for (double v : x)
            cout << (v - mean) / stdv << " ";

    } else if (scaler == "MINMAX") {
        double mn = *min_element(x.begin(), x.end());
        double mx = *max_element(x.begin(), x.end());

        double diff = mx - mn;
        for (double v : x)
            cout << (v - mn) / diff << " ";

    } else if (scaler == "ROBUST") {
        vector<double> t = x;
        sort(t.begin(), t.end());
        double med = t[N/2];
        double q1 = t[N/4];
        double q3 = t[3*N/4];
        double iqr = q3 - q1;

        for (double v : x)
            cout << (v - med) / iqr << " ";
    }

    return 0;
}
