#include <bits/stdc++.h>

using namespace std;

map<int, pair<int, int> > m;

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

int lastNode(node root) {
    queue<node> que;
    que.push(root);
    bool haveEnd = false;
    node temp;
    while (!que.empty()) {
        temp = que.front();
        que.pop();
        if (temp->left != NULL) {
            if (haveEnd) return -1;
            que.push(temp->left);
        } else
            haveEnd = true;
        if (temp->right != NULL) {
            if (haveEnd) return -1;
            que.push(temp->right);
        } else
            haveEnd = true;
    }
    return temp->val;
}

node buildTree(int r) {
    if (r < 0) return NULL;
    node root = new Node(r);
    if (m.find(r) != m.end() && m[r].first != -1)
        root->left = buildTree(m[r].first);
    if (m.find(r) != m.end() && m[r].second != -1)
        root->right = buildTree(m[r].second);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<bool> haveParent(n, false);
    for (int i = 0; i < n; ++i) {
        string left, right;
        cin >> left >> right;
        pair<int, int> temp = {-1, -1};
        if (left[0] != '-') {
            int l = stoi(left);
            haveParent[l] = true;
            temp.first = l;
        }
        if (right[0] != '-') {
            int r = stoi(right);
            haveParent[r] = true;
            temp.second = r;
        }
        m[i] = temp;
    }

    int r = 0;
    while (haveParent[r]) r++;

    node root = buildTree(r);
    int last = lastNode(root);
    if (last < 0)
        cout << "NO " << root->val << endl;
    else
        cout << "YES " << last << endl;

    return 0;
}