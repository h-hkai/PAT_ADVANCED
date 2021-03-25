#include <iostream>
#include <vector>

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

node buildTree(vector<int>& v, int start, int end) {
    if (start > end) return NULL;
    node root = new Node(v[start]);
    int pos = start + 1;
    while (pos <= end && v[pos] < v[start]) ++pos;
    if (pos == start + 1) {
        root->right = buildTree(v, start + 1, end);
    } else if (pos == end + 1) {
        root->left = buildTree(v, start + 1, end);
    } else {
        root->left = buildTree(v, start + 1, pos - 1);
        root->right = buildTree(v, pos, end);
    }
    return root;
}

bool foundNode(node root, int x) {
    if (root == NULL) return false;
    if (root->val == x) return true;
    return foundNode(root->left, x) || foundNode(root->right, x);
}

node LCA(node root, int x, int y) {
    if (root == NULL) return NULL;
    if (root->val == x || root->val == y) return root;
    node left = LCA(root->left, x, y);
    node right = LCA(root->right, x, y);
    return !left ? right : !right ? left : root;
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> num(N);
    for (int i = 0; i < N; ++i) cin >> num[i];
    node root = buildTree(num, 0, N - 1);
    // perOrder(root);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        bool foundX = foundNode(root, x);
        bool foundY = foundNode(root, y);
        if (foundX && foundY) {
            node lca = LCA(root, x, y);
            if (lca->val == x)
                cout << x << " is an ancestor of " << y << "." << endl;
            else if (lca->val == y)
                cout << y << " is an ancestor of " << x << "." << endl;
            else
                cout << "LCA of " << x << " and " << y << " is " << lca->val
                     << "." << endl;
        } else if (foundX) {
            cout << "ERROR: " << y << " is not found." << endl;
        } else if (foundY) {
            cout << "ERROR: " << x << " is not found." << endl;
        } else {
            cout << "ERROR: " << x << " and " << y << " are not found." << endl;
        }
    }
    return 0;
}