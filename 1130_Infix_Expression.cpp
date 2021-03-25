#include <bits/stdc++.h>

using namespace std;

typedef struct Node* node;

struct Node {
    string date;
    int left;
    int right;
    node leftNode;
    node rightNode;
    bool isRoot;
    Node(string s, int l, int r) {
        date = s;
        left = l;
        right = r;
        leftNode = NULL;
        rightNode = NULL;
        isRoot = true;
    }
};

bool isFirst = true;

void inTraverl(node root) {
    if (root == NULL) return;
    bool haveParentheses = false;
    if (isFirst)
        isFirst = false;
    else {
        if (root->leftNode || root->rightNode) {
            cout << "(";
            haveParentheses = true;
        }
    }

    inTraverl(root->leftNode);
    cout << root->date;
    inTraverl(root->rightNode);
    if (haveParentheses) cout << ")";
}

int main() {
    int n;
    cin >> n;
    vector<node> v(n + 1);
    string str;
    int left, right;
    for (int i = 1; i <= n; ++i) {
        cin >> str >> left >> right;
        v[i] = new Node(str, left, right);
    }
    node root;
    for (int i = 1; i <= n; ++i) {
        if (v[i]->left != -1) {
            v[i]->leftNode = v[v[i]->left];
            v[v[i]->left]->isRoot = false;
        }
        if (v[i]->right != -1) {
            v[i]->rightNode = v[v[i]->right];
            v[v[i]->right]->isRoot = false;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i]->isRoot) {
            root = v[i];
            break;
        }
    }

    inTraverl(root);

    return 0;
}