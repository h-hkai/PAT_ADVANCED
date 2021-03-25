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

void levelTravelTree(node root) {
    queue<node> que;
    que.push(root);
    que.push(NULL);
    vector<int> v(1005);
    int count = 0, index = 1;
    while (!que.empty()) {
        node q = que.front();
        que.pop();
        if (q == NULL) {
            que.push(NULL);
            v[index++] = count;
            count = 0;
            if (que.size() == 1) break;
        } else {
            if (q->left) que.push(q->left);
            if (q->right) que.push(q->right);
            count++;
        }
    }
    cout << v[index - 1] << " + " << v[index - 2] << " = "
         << v[index - 2] + v[index - 1] << endl;
}

int main() {
    int n, v;
    cin >> n;
    node root = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        node temp = root;
        while (temp != NULL)
            if (v > temp->val && temp->right != NULL)
                temp = temp->right;
            else if (v <= temp->val && temp->left != NULL)
                temp = temp->left;
            else
                break;
        if (root == NULL)
            root = new Node(v);
        else if (v > temp->val)
            temp->right = new Node(v);
        else
            temp->left = new Node(v);
    }

    levelTravelTree(root);

    return 0;
}