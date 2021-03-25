#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m;
    vector<vector<int> > grap(n + 1, vector<int>(n + 1, 0));
    int v1, v2;
    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2;
        grap[v1][v2] = 1;
        grap[v2][v1] = 1;
    }
    cin >> k;
    int num;
    set<int> s;
    bool isHamiltonianCycle;
    for (int i = 0; i < k; ++i) {
        cin >> num;
        vector<int> v(num);
        s.clear();
        isHamiltonianCycle = true;
        for (int j = 0; j < num; ++j) {
            cin >> v[j];
            s.insert(v[j]);
        }
        if (num != n + 1 || s.size() != n)
            isHamiltonianCycle = false;
        else {
            for (int j = 1; j < num; ++j) {
                if (grap[v[j]][v[j - 1]] == 0) {
                    isHamiltonianCycle = false;
                    break;
                }
            }
        }
        if (v[0] != v[num - 1]) isHamiltonianCycle = false;
        if (isHamiltonianCycle)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}