#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    vector<int> sons;
    int father = -1;
    int sum = 0;
};

vector<int> leaf;
vector<Node> v;

bool cmp(int a, int b) { return v[a].val > v[b].val; }

void DFS(int index, int s) {
    if (v[index].father != -1) {
        int father = v[index].father;
        v[index].sum = v[father].sum + v[index].val;
    }
    if (v[index].sons.size() == 0) {
        if (v[index].sum == s) {
            vector<int> path;
            while (v[index].father != -1) {
                path.push_back(v[index].val);
                index = v[index].father;
            }
            path.push_back(v[index].val);
            reverse(path.begin(), path.end());
            for (int i = 0; i < path.size(); ++i) {
                if (i == 0)
                    cout << path[i];
                else
                    cout << " " << path[i];
            }
            cout << endl;
        }
        return;
    }
    for (int son : v[index].sons) DFS(son, s);
}

int main() {
    int n, m;
    long long s;
    cin >> n >> m >> s;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].val;
        v[i].sum = v[i].val;
    }
    for (int i = 0; i < m; ++i) {
        int index, k, son;
        cin >> index >> k;
        v[index].sum = v[index].val;
        for (int j = 0; j < k; ++j) {
            cin >> son;
            v[index].sons.push_back(son);
            v[son].father = index;
        }
        sort(v[index].sons.begin(), v[index].sons.end(), cmp);
    }
    DFS(0, s);
    return 0;
}