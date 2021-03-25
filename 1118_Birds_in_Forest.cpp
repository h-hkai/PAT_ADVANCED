#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;
vector<int> fa(10005);

int findFather(int x) {
    int a = x;
    while (x != fa[x]) {
        x = fa[x];
    }
    while (a != fa[a]) {
        int z = a;
        a = fa[a];
        fa[z] = x;
    }
    return x;
}

void Union(int x, int y) {
    int faX = findFather(x);
    int faY = findFather(y);
    if (faX != faY) fa[faY] = faX;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < maxn; ++i) {
        fa[i] = i;
    }

    int k, id, m;
    vector<bool> exist(10005, false);
    vector<int> cnt(10005, 0);
    int numTrees = 0;
    int numBirds = 0;
    for (int i = 0; i < n; ++i) {
        cin >> k >> id;
        exist[id] = true;
        for (int j = 1; j < k; ++j) {
            cin >> m;
            exist[m] = true;
            Union(id, m);
        }
    }
    for (int i = 1; i < maxn; ++i) {
        if (exist[i]) {
            int root = findFather(i);
            cnt[root]++;
        }
    }
    for (int i = 1; i < maxn; ++i) {
        if (exist[i] && cnt[i] > 0) {
            numTrees++;
            numBirds += cnt[i];
        }
    }
    cout << numTrees << " " << numBirds << endl;
    int querys;
    cin >> querys;
    for (int i = 0; i < querys; ++i) {
        int bird1, bird2;
        cin >> bird1 >> bird2;
        if (findFather(bird1) == findFather(bird2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}