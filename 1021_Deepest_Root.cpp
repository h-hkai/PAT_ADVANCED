#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> ans;
vector<bool> visited;
vector<vector<int> > grap;
int max_deep = 0;

void DFS(int node, int level) {
    if (max_deep < level) {
        ans.clear();
        ans.push_back(node);
        max_deep = level;
    } else if (max_deep == level) {
        ans.push_back(node);
    }
    visited[node] = true;
    for (int it : grap[node]) {
        if (visited[it] == false) {
            DFS(it, level + 1);
        }
    }
}

int main() {
    int v1, v2;
    cin >> n;
    grap.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 1; i < n; ++i) {
        cin >> v1 >> v2;
        grap[v1].push_back(v2);
        grap[v2].push_back(v1);
    }
    int count = 0, s1 = 0;
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == false) {
            DFS(i, 1);
            if (i == 1) {
                if (ans.size() != 0) s1 = ans[0];
                for (int it : ans) s.insert(it);
            }
            count++;
        }
    }

    if (count > 1) {
        cout << "Error: " << count << " components" << endl;
    } else {
        ans.clear();
        max_deep = 0;
        visited.clear();
        visited.resize(n + 1, false);
        DFS(s1, 1);
        for (int it : ans) s.insert(it);
        for (int it : s) cout << it << endl;
    }
    return 0;
}