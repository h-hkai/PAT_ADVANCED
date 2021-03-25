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

vector<int> pre, post;
bool isUnique = true;

node buildTree(int preStart, int preEnd, int postStart, int postEnd) {
    int pos = 0, len1, len2;
    if (preStart > preEnd || postStart > postEnd) return NULL;
    node root = new Node(pre[preStart]);
    for (int i = preStart; i <= preEnd; ++i) {
        if (pre[i] == post[postEnd - 1]) {
            pos = i;
            break;
        }
    }
    len1 = preEnd - pos + 1;    // 右子树的长度
    len2 = pos - preStart - 1;  // 左子树的长度

    if (len1 * len2 == 0) isUnique = false;
    if (len1 < 0 || len2 < 0) return root;

    root->left =
        buildTree(preStart + 1, pos - 1, postStart, postEnd - len1 - 1);
    root->right = buildTree(pos, preEnd, postStart + len2, postEnd - 1);

    return root;
}

bool isFirst = true;
void InorderTravelTree(node root) {
    if (root == NULL) return;
    InorderTravelTree(root->left);
    if (isFirst) {
        cout << root->val;
        isFirst = false;
    } else {
        cout << " " << root->val;
    }
    InorderTravelTree(root->right);
}

int main() {
    int n, t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        pre.push_back(t);
    }
    for (int i = 0; i < n; ++i) {
        cin >> t;
        post.push_back(t);
    }
    node root = buildTree(0, n - 1, 0, n - 1);

    if (isUnique)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    InorderTravelTree(root);

    return 0;
}