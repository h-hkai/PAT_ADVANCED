#include <bits/stdc++.h>

using namespace std;

vector<int> grap[1005];

int helper(int query, int level) {
    queue<int> que;
    que.push(query);
    que.push(-1);
    int count = 0;
    vector<bool> visited(1005, false);
    visited[query] = true;
    while (!que.empty() && level >= 0) {
        int temp = que.front();
        que.pop();
        if (temp != -1) count++;
        if (temp == -1) {
            level--;
            if (que.empty()) break;
            que.push(-1);
        } else {
            for (int i = 0; i < grap[temp].size(); ++i) {
                if (!visited[grap[temp][i]]) {
                    visited[grap[temp][i]] = true;
                    que.push(grap[temp][i]);
                }
            }
        }
    }
    return count - 1;
}

int main() {
    int n, l, k, t;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> t;
            grap[t].push_back(i);
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> t;
        cout << helper(t, l) << endl;
    }

    return 0;
}