#include <bits/stdc++.h>

using namespace std;

typedef struct Node* node;

struct Node {
    int val;
    node left;
    node right;
    Node(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

vector<int> postOrder;
vector<int> inOrder;

int n;

void LevelOrderTravel(node root) {
    queue<node> que;
    que.push(root);
    bool isFirst = true;
    while (!que.empty()) {
        if (isFirst) {
            isFirst = false;
            cout << que.front()->val;
        } else {
            cout << " " << que.front()->val;
        }
        if (que.front()->left) que.push(que.front()->left);
        if (que.front()->right) que.push(que.front()->right);
        que.pop();
    }
}

node buildTree(int l1, int r1, int l2, int r2) {
    if (l1 > r1 || l2 > r2) return NULL;
    int val = postOrder[r1];
    node root = new Node(val);
    int pos = 0;
    for (int i = l2; i <= r2; ++i) {
        if (inOrder[i] == val) {
            pos = i;
            break;
        }
    }
    int rightLen = r2 - pos;
    int leftLen = pos - l2;
    root->right = buildTree(r1 - rightLen, r1 - 1, pos + 1, r2);
    root->left = buildTree(l1, l1 + leftLen - 1, l2, l2 + leftLen - 1);
    return root;
}

int main() {
    cin >> n;
    postOrder.resize(n + 1, 0);
    inOrder.resize(n + 1, 0);
    for (int i = 0; i < n; ++i) cin >> postOrder[i];
    for (int i = 0; i < n; ++i) cin >> inOrder[i];
    node root = buildTree(0, n - 1, 0, n - 1);
    LevelOrderTravel(root);
    return 0;
}