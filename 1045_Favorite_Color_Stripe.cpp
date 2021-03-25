#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m;
    vector<int> colors(n + 1);
    set<int> found;
    for (int i = 1; i <= m; ++i) cin >> colors[i];
    cin >> l;
    vector<int> stripe(l + 1);
    for (int i = 1; i <= l; ++i) cin >> stripe[i];
    vector<vector<int> > dp(n + 1, vector<int>(l + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= l; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (colors[i] == stripe[j]) dp[i][j]++;
        }
    }
    cout << dp[n][l] << endl;
    return 0;
}