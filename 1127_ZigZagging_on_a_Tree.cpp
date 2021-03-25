#include <bits/stdc++.h>

using namespace std;

vector<int> inOrder(50);
vector<int> postOrder(50);

typedef struct Node* node;

struct Node {
    int date;
    node left;
    node right;
    Node(int v) {
        date = v;
        left = NULL;
        right = NULL;
    }
};

node buildTree(int index, int left, int right) {
    if (left > right) return NULL;
    node root = new Node(postOrder[index]);
    int pos;
    for (int i = left; i <= right; ++i) {
        if (inOrder[i] == postOrder[index]) {
            pos = i;
            break;
        }
    }
    int len = right - pos;
    root->left = buildTree(index - len - 1, left, pos - 1);
    root->right = buildTree(index - 1, pos + 1, right);
    return root;
}

void levelOrder(node root) {
    queue<node> que;
    deque<int> level;
    vector<int> ans;
    node last = new Node(-1);
    que.push(root);
    que.push(last);
    bool leftToRight = false;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp->date == -1) {
            if (que.empty() && level.empty()) break;
            que.push(last);
            if (leftToRight) {
                while (!level.empty()) {
                    ans.push_back(level.front());
                    level.pop_front();
                }
                leftToRight = false;
            } else {
                while (!level.empty()) {
                    ans.push_back(level.back());
                    level.pop_back();
                }
                leftToRight = true;
            }
        } else {
            level.push_back(temp->date);
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
        }
    }
    cout << ans[0];
    for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> inOrder[i];
    for (int i = 0; i < n; ++i) cin >> postOrder[i];

    node root = buildTree(n - 1, 0, n - 1);

    levelOrder(root);

    return 0;
}