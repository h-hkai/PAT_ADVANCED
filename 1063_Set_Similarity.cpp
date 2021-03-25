#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, t;
    cin >> n;
    vector<set<int> > v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> t;
            v[i].insert(t);
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int q1, q2;
        cin >> q1 >> q2;
        int total = v[q1].size() + v[q2].size();
        int count = 0;
        for (int s : v[q1])
            if (v[q2].find(s) != v[q2].end()) count++;
        cout << fixed << setprecision(1)
             << (double)count / (total - count) * 100 << "%" << endl;
    }

    return 0;
}