#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    for (int i = 0; i < k; ++i) {
        vector<int> seq(n);
        for (int j = 0; j < n; ++j) cin >> seq[j];
        int cur = 0;
        stack<int> s;
        for (int j = 1; j <= n; ++j) {
            s.push(j);
            if (s.size() > m) break;
            while (!s.empty() && s.top() == seq[cur]) {
                s.pop();
                cur++;
            }
        }
        if (cur == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}