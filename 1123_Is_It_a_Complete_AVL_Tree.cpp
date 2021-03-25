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

node leftRightRotate(node root) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
}

node rightLeftRotate(node root) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
}

int findHeight(node root) {
    if (root == NULL) return 0;
    int l = findHeight(root->left);
    int r = findHeight(root->right);
    return max(l, r) + 1;
}

void insertNode(int v, node& root) {
    if (root == NULL) {
        root = new Node(v);
    } else if (v < root->val) {
        insertNode(v, root->left);
        int l = findHeight(root->left);
        int r = findHeight(root->right);
        if (abs(r - l) >= 2) {
            if (v < root->left->val) {
                root = rightRotate(root);
            } else {
                root = leftRightRotate(root);
            }
        }
    } else {
        insertNode(v, root->right);
        int l = findHeight(root->left);
        int r = findHeight(root->right);
        if (abs(r - l) >= 2) {
            if (v > root->right->val) {
                root = leftRotate(root);
            } else {
                root = rightLeftRotate(root);
            }
        }
    }
}

bool levelTravel(node root) {
    queue<node> que;
    que.push(root);
    bool isCompleteBinaryTree = true;
    bool isFirst = true;
    bool isStart = false;
    cout << root->val;
    while (!que.empty()) {
        node temp = que.front();
        if (isStart)
            cout << " " << temp->val;
        else
            isStart = true;
        que.pop();
        if (temp->left) {
            que.push(temp->left);
            if (!isFirst) isCompleteBinaryTree = false;
        } else if (isFirst) {
            isFirst = false;
        }
        if (temp->right) {
            que.push(temp->right);
            if (!isFirst) isCompleteBinaryTree = false;
        } else if (isFirst) {
            isFirst = false;
        }
    }
    cout << endl;
    return isCompleteBinaryTree;
}

int main() {
    int n, t;
    cin >> n;
    node root = NULL;
    while (n--) {
        cin >> t;
        insertNode(t, root);
    }
    if (levelTravel(root))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}