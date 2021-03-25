#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<int> post;

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

bool isBST() {
    bool found1 = false;
    for (int i = 1; i < n; ++i) {
        if (v[i] >= v[0]) found1 = true;
        if (found1 && v[i] < v[0]) return false;
    }
    return true;
}

bool isMIBST() {
    bool found2 = false;
    for (int i = 1; i < n; ++i) {
        if (v[i] < v[0]) found2 = true;
        if (found2 && v[i] >= v[0]) return false;
    }
    return true;
}

node buildTree(int s, int e, bool isBST) {
    if (s > e) return NULL;
    node root = new Node(v[s]);
    int pos = -1;
    if (isBST) {
        for (int i = s + 1; i <= e; ++i)
            if (v[i] >= v[s]) {
                pos = i;
                break;
            }
    } else {
        for (int i = s + 1; i <= e; ++i)
            if (v[i] < v[s]) {
                pos = i;
                break;
            }
    }
    if (pos == -1) return root;
    root->left = buildTree(s + 1, pos - 1, isBST);
    root->right = buildTree(pos, e, isBST);
    return root;
}

void postOrder(node root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    post.push_back(root->val);
}

int main() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n; ++i) cin >> v[i];
    node root;
    if (isBST()) {
        cout << "YES" << endl;
        root = buildTree(0, n - 1, true);
    } else if (isMIBST()) {
        cout << "YES" << endl;
        root = buildTree(0, n - 1, false);
    } else {
        cout << "NO" << endl;
        return 0;
    }
    postOrder(root);
    bool isFirst = true;
    for (int i : post) {
        if (isFirst) {
            cout << i;
            isFirst = false;
        } else {
            cout << " " << i;
        }
    }
    cout << endl;
    return 0;
}