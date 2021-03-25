#include<iostream>
#include<vector>
#include<set>

using namespace std;

typedef struct Node* node;

struct Node {
    int val;
    node left;
    node right;

    Node() {
        val = 0;
        left = NULL;
        right = NULL;
    }

    Node(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

vector<int> inorder, preorder;
int tag = 0;

node buildTree(int start, int end, int tag) {
    if (start >= end || tag >= inorder.size()) return NULL;
    int val = preorder[tag];
    node root = new Node(val);
    int lend, rstart, pos;
    for (int i = 0; i < inorder.size(); ++i) {
        if (inorder[i] == val) {
            pos = i;
            break;
        }
    }
    lend = pos - 1;
    rstart = pos + 1;
    root->left = buildTree(start, lend, tag+1);
    root->right = buildTree(rstart, end, tag+pos+1);
    return root;
}

node lowestCommonAncestor(node root, int n1, int n2) {
    if (!root || root->val == n1 || root->val == n2) return root;
    node left = lowestCommonAncestor(root->left, n1, n2);
    node right = lowestCommonAncestor(root->right, n1, n2);
    return !left ? right : !right ? left : root;
}

int main() {
    int m, n, t;
    cin >> m >> n;

    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        inorder.push_back(t);
        s.insert(t);
    }
    for (int i = 0; i < n; ++i) {
        cin >> t;
        preorder.push_back(t);
    }

    node root = buildTree(0, n-1, 0);

    for (int i = 0; i < m; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        if (s.find(n1) != s.end() && s.find(n2) != s.end()) {
            node lca = lowestCommonAncestor(root, n1, n2);
            int v = lca->val;
            if (v == n1) {
                cout << n1 << " is an ancestor of " << n2 << "." << endl;
            } else if (v == n2) {
                cout << n2 << " is an ancestor of " << n1 << "." << endl;
            } else {
                cout << "LCA of " << n1 << " and " << n2 << " is " << v << "." << endl;
            }
        } else if (s.find(n1) != s.end()) {
            cout << "ERROR: " << n2 << " is not found." << endl;
        } else if (s.find(n2) != s.end()) {
            cout << "ERROR: " << n1 << " is not found." << endl;
        } else {
            cout << "ERROR: " << n1 << " and " << n2 << " are not found." << endl;
        }

    }
    



    return 0;
}