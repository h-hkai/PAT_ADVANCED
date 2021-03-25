#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef struct Node *node;

struct Node {
    int num;
    int data;
    node left;
    node right;
    bool filled = false;
};

node BST = (node)malloc(sizeof(struct Node));

void level_traver(node t) {
    node tmp;
    queue<node> q;
    q.push(t);
    tmp = q.front();
    q.pop();
    if (tmp->left) q.push(tmp->left);
    if (tmp->right) q.push(tmp->right);
    cout << tmp->data;

    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        if (tmp->left) q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
        cout << " " << tmp->data;
    }
}

node insert(node t) {
    if (t == NULL) return NULL;
    if (!t->left && !t->filled) return t;
    node ret = insert(t->left);
    if (ret != NULL) return ret;
    if (t->left && t->left->filled && !t->filled) return t;
    ret = insert(t->right);
    if (ret != NULL) return ret;
    else return NULL;
}

node find_dummy(node t, int n) {
    if (t == NULL) return NULL;
    if (t->num == n) return t;
    node ret = find_dummy(t->left, n);
    if (ret != NULL) return ret;
    ret = find_dummy(t->right, n);
    if (ret != NULL) return ret;
    else return NULL;
}

int main() {
    int n;
    cin >> n;

    BST->num = 0;
    node dummy, ptr;

    for (int i = 0; i < n; ++i) {
        ptr = BST;
        dummy = find_dummy(ptr, i);
        int left_index, right_index;
        cin >> left_index >> right_index;
        if (left_index > 0) {
            node temp = (node)malloc(sizeof(struct Node));
            temp->num = left_index;
            dummy->left = temp;
        } else dummy->left = NULL;
        if (right_index > 0) {
            node temp = (node)malloc(sizeof(struct Node));
            temp->num = right_index;
            dummy->right = temp;
        } else dummy->right = NULL;
    }

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i) {
        ptr = BST;
        node tmp = insert(ptr);
        tmp->data = v[i];
        tmp->filled = true;
    }

    level_traver(BST);

    return 0;
}