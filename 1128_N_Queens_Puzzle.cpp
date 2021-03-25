#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, t;
    bool isSolution;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        vector<int> v(k + 5);
        set<int> s;
        isSolution = true;
        for (int j = 1; j <= k; ++j) cin >> v[j];
        for (int j = 1; j <= k; ++j) {
            for (int p = j + 1; p < k; ++p) {
                if (v[j] == v[p] || abs(v[j] - v[p]) == abs(j - p)) {
                    isSolution = false;
                    break;
                }
            }
            if (!isSolution) break;
        }
        if (isSolution)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}