#include <bits/stdc++.h>

using namespace std;

char name[40005][5];
bool cmp(int a, int b) {
    if (strcmp(name[a], name[b]) < 0)
        return true;
    else
        return false;
}

int main() {
    int n, k, c, t;
    scanf("%d%d", &n, &k);
    vector<vector<int> > v(k + 1);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", name[i], &c);
        for (int j = 0; j < c; ++j) {
            scanf("%d", &t);
            v[t].push_back(i);
        }
    }
    for (int i = 1; i <= k; ++i) {
        printf("%d %d\n", i, v[i].size());
        sort(v[i].begin(), v[i].end(), cmp);
        for (int j = 0; j < v[i].size(); ++j) printf("%s\n", name[v[i][j]]);
    }
    return 0;
}