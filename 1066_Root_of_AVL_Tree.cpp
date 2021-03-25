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

node rightRotate(node root) {
    node temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

node leftRotate(node root) {
    node temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

node rightLeft(node root) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
}

node leftRight(node root) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
}

int findHeight(node root) {
    if (root == NULL) return 0;
    int l = findHeight(root->left);
    int r = findHeight(root->right);
    return max(l, r) + 1;
}

void insertNode(node& root, int val) {
    if (root == NULL) {
        root = new Node(val);
    } else if (root->val > val) {
        insertNode(root->left, val);
        int l = findHeight(root->left);
        int r = findHeight(root->right);
        if (abs(r - l) > 1) {
            if (root->left->val > val) {
                root = rightRotate(root);
            } else {
                root = leftRight(root);
            }
        }
    } else {
        insertNode(root->right, val);
        int l = findHeight(root->left);
        int r = findHeight(root->right);
        if (abs(r - l) > 1) {
            if (root->right->val < val) {
                root = leftRotate(root);
            } else {
                root = rightLeft(root);
            }
        }
    }
}

void preTraveser(node root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preTraveser(root->left);
    preTraveser(root->right);
}

int main() {
    int n, t;
    cin >> n;
    node root = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        insertNode(root, t);
    }
    cout << root->val << endl;
    return 0;
}