#include <bits/stdc++.h>

using namespace std;

vector<int> grap[505];
set<int> s;

void DFS(int index) {
    if (s.find(index) != s.end()) return;
    s.insert(index);
    for (int g : grap[index]) {
        DFS(g);
    }
}

int main() {
    int n, m, v1, v2;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2;
        grap[v1].push_back(v2);
        grap[v2].push_back(v1);
    }
    int even = 0, odd = 0;
    cout << grap[1].size();
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << " " << grap[i].size();
        if (grap[i].size() % 2 == 0)
            even++;
        else
            odd++;
    }
    cout << endl;
    DFS(1);
    if (s.size() != n)
        cout << "Non-Eulerian" << endl;
    else {
        if (even == n)
            cout << "Eulerian" << endl;
        else if (odd == 2)
            cout << "Semi-Eulerian" << endl;
        else
            cout << "Non-Eulerian" << endl;
    }
    return 0;
}