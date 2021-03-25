#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m;

    vector<vector<int> > grap(n + 1);
    int v1, v2;
    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2;
        grap[v1].push_back(v2);
        grap[v2].push_back(v1);
    }

    cin >> k;
    int nv, t, edges;
    unordered_set<int> uset;
    for (int i = 0; i < k; ++i) {
        cin >> nv;
        uset.clear();
        edges = 0;
        for (int j = 0; j < nv; ++j) {
            cin >> t;
            uset.insert(t);
            for (int k : grap[t])
                if (uset.find(k) == uset.end()) edges++;
        }
        if (edges == m)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}