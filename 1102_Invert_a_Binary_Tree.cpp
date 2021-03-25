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

map<int, pair<int, int> > m;
node buildTree(int r) {
    node root = new Node(r);
    if (m[r].first != -1) {
        root->left = buildTree(m[r].first);
    }
    if (m[r].second != -1) {
        root->right = buildTree(m[r].second);
    }
    return root;
}

void levelOrder(node root) {
    queue<node> que;
    que.push(root);
    bool isFirst = true;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        if (isFirst) {
            cout << temp->val;
            isFirst = false;
        } else {
            cout << " " << temp->val;
        }
        if (temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
    }
    cout << endl;
}

bool isFirst = true;
void inOrder(node root) {
    if (root == NULL) return;
    inOrder(root->left);
    if (isFirst) {
        cout << root->val;
        isFirst = false;
    } else {
        cout << " " << root->val;
    }
    inOrder(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> fa(n, -1);
    for (int i = 0; i < n; ++i) {
        char l, r;
        cin >> l >> r;
        pair<int, int> temp = {-1, -1};
        if (isdigit(l)) {
            fa[l - '0'] = i;
            temp.second = l - '0';
        }
        if (isdigit(r)) {
            fa[r - '0'] = i;
            temp.first = r - '0';
        }
        m[i] = temp;
    }
    int r;
    for (int i = 0; i < n; ++i)
        if (fa[i] == -1) r = i;

    node root = buildTree(r);

    levelOrder(root);
    inOrder(root);
    cout << endl;

    return 0;
}