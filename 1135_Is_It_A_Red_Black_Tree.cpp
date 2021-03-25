#include <bits/stdc++.h>

using namespace std;

typedef struct Node* node;

struct Node {
    int val;
    int color;
    node left;
    node right;
    Node(int v, int c) {
        val = v;
        color = c;
        left = NULL;
        right = NULL;
    }
};

node buildTree(vector<node>& v) {
    node root = v[0];
    for (int i = 1; i < v.size(); ++i) {
        node temp = root;
        while (temp != NULL) {
            if (v[i]->val < temp->val) {
                if (temp->left != NULL)
                    temp = temp->left;
                else {
                    temp->left = v[i];
                    break;
                }
            } else {
                if (temp->right != NULL)
                    temp = temp->right;
                else {
                    temp->right = v[i];
                    break;
                }
            }
        }
    }
    return root;
}

bool travelTree(node root) {
    if (root == NULL) return true;
    if (root->color == -1) {
        if (root->left && root->left->color == -1) return false;
        if (root->right && root->right->color == -1) return false;
    }
    bool left = travelTree(root->left);
    bool right = travelTree(root->right);
    return left && right;
}

vector<int> nums;

void judgeFunction(node root, int level) {
    if (root == NULL) {
        nums.push_back(level);
        return;
    }
    if (root->color == 1) level = level + 1;
    judgeFunction(root->left, level);
    judgeFunction(root->right, level);
}

bool isRedBlackTree(node root) {
    if (root->color == -1) return false;
    if (!travelTree(root)) return false;
    nums.clear();
    judgeFunction(root, 0);
    for (int i = 1; i < nums.size(); ++i) {
        // cout << nums[i] << " ";
        if (nums[i - 1] != nums[i]) return false;
    }

    return true;
}

int main() {
    int n, k, t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        node temp;
        vector<node> v;
        for (int j = 0; j < k; ++j) {
            cin >> t;
            if (t > 0)
                temp = new Node(t, 1);
            else
                temp = new Node(-t, -1);
            v.push_back(temp);
        }
        node root = buildTree(v);
        if (isRedBlackTree(root))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}