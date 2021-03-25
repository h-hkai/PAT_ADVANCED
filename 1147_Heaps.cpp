#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct Node* node;

struct Node {
    int val;
    node left;
    node right;
    bool isroot;
    Node(int v) {
        val = v;
        left = NULL;
        right = NULL;
        isroot = false;
    }
};

node buildTree(queue<int>& val) {
    node root = new Node(val.front());
    root->isroot = true;
    val.pop();
    queue<node> que;
    que.push(root);
    while (!que.empty() && !val.empty()) {
        node father = que.front();
        que.pop();
        node l = new Node(val.front());
        val.pop();
        father->left = l;
        que.push(l);
        if (!val.empty()) {
            node r = new Node(val.front());
            val.pop();
            father->right = r;
            que.push(r);
        }
    }
    return root;
}

void postOrderTravel(node root) {
    if (root == NULL) return;
    postOrderTravel(root->left);
    postOrderTravel(root->right);
    if (root->isroot)
        cout << root->val << endl;
    else
        cout << root->val << " ";
}

bool isMaxHeap(node root) {
    bool left = true, right = true;
    if (root->left) {
        left = isMaxHeap(root->left);
        if (root->val < root->left->val) return false;
    }
    if (root->right) {
        right = isMaxHeap(root->right);
        if (root->val < root->right->val) return false;
    }
    return left && right;
}

bool isMinHeap(node root) {
    bool left = true, right = true;
    if (root->left) {
        left = isMinHeap(root->left);
        if (root->val > root->left->val) return false;
    }
    if (root->right) {
        right = isMinHeap(root->right);
        if (root->val > root->right->val) return false;
    }
    return left && right;
}

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        int temp;
        queue<int> val;
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            val.push(temp);
        }
        node root = buildTree(val);
        if (isMaxHeap(root)) {
            cout << "Max Heap" << endl;
        } else if (isMinHeap(root)) {
            cout << "Min Heap" << endl;
        } else {
            cout << "Not Heap" << endl;
        }
        postOrderTravel(root);
    }

    return 0;
}