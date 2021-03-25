#include <bits/stdc++.h>

using namespace std;

vector<int> preOrder;
vector<int> inOrder;
bool found = false;

void buildTree(int root, int start, int end) {
    if (start > end) return;
    int i = start;
    while (i <= end && inOrder[i] != preOrder[root]) ++i;
    int len = i - start;
    buildTree(root + 1, start, i - 1);
    buildTree(root + len + 1, i + 1, end);
    if (!found) {
        cout << inOrder[i] << endl;
        found = true;
    }
}

int main() {
    int n;
    cin >> n;
    preOrder = vector<int>(n);
    inOrder = vector<int>(n);
    for (int i = 0; i < n; ++i) cin >> preOrder[i];
    for (int i = 0; i < n; ++i) cin >> inOrder[i];
    buildTree(0, 0, n - 1);
    return 0;
}