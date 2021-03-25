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

void buildTree(node& root, int num) {
    queue<node> que;
    que.push(root);
    int count = 1;
    while (count < num) {
        node temp = que.front();
        que.pop();
        temp->left = new Node(-1);
        que.push(temp->left);
        count++;
        if (count < num) {
            temp->right = new Node(-1);
            que.push(temp->right);
            count++;
        }
    }
};

int tempIndex = 0;
void inorderTraveral(node& root, vector<int>& keys) {
    if (root == NULL) return;
    inorderTraveral(root->left, keys);
    root->val = keys[tempIndex++];
    inorderTraveral(root->right, keys);
}

void levelTraveral(node& root) {
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
        if (temp->left != NULL) que.push(temp->left);
        if (temp->right != NULL) que.push(temp->right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> keys(n);
    for (int i = 0; i < n; ++i) cin >> keys[i];
    sort(keys.begin(), keys.end());
    node root = new Node(-1);
    buildTree(root, n);
    inorderTraveral(root, keys);
    levelTraveral(root);
    return 0;
}