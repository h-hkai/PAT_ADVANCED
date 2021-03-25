#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coins(n + 1, 0);
    vector<int> dp(m + 5, 0);
    bool choice[10005][105] = {false};
    for (int i = 1; i <= n; ++i) cin >> coins[i];
    sort(coins.begin() + 1, coins.end(), greater<int>());
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= coins[i]; --j) {
            if (dp[j] <= dp[j - coins[i]] + coins[i]) {
                dp[j] = dp[j - coins[i]] + coins[i];
                choice[i][j] = true;
            }
        }
    }
    if (dp[m] != m)
        cout << "No Solution";
    else {
        vector<int> ans;
        int volume = m, index = n;
        while (volume > 0) {
            if (choice[index][volume]) {
                ans.push_back(coins[index]);
                volume -= coins[index];
            }
            --index;
        }
        for (int i = 0; i < ans.size(); ++i) {
            if (i == 0)
                cout << ans[i];
            else
                cout << " " << ans[i];
        }
    }
    cout << endl;
    return 0;
}