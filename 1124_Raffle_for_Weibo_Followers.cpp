#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, k, index;
    cin >> m >> n >> k;
    set<string> s;
    vector<string> followers(m + 1), ans;
    for (int i = 1; i <= m; ++i) {
        cin >> followers[i];
    }
    if (m < k)
        ans.push_back("Keep going...");
    else {
        while (k <= m) {
            if (s.find(followers[k]) == s.end()) {
                s.insert(followers[k]);
                ans.push_back(followers[k]);
            } else {
                while (k <= m && s.find(followers[k]) != s.end()) {
                    k++;
                }
                ans.push_back(followers[k]);
            }
            k += n;
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}