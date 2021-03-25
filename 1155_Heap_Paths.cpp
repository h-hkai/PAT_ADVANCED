#include<iostream>
#include<queue>
#include<stack>

using namespace std;

queue<int> que;
stack<int> path;
queue<int> temp;
bool isMaxHeap = true;
bool isMinHeap = true;

typedef struct Node* node;

struct Node {
    int value;
    node left;
    node right;
    Node() {
        value = 0;
        left = NULL;
        right = NULL;
    }
};

node root = new Node();
queue<node> nodeQue;

void buildTree() {
    root->value = que.front();
    que.pop();
    nodeQue.push(root);
    while(!que.empty()) {
        node parent = nodeQue.front(); 
        nodeQue.pop();
        node left = new Node();
        node right = new Node();
        if (!que.empty()) {
            left->value = que.front();
            parent->left = left;
            nodeQue.push(left);
            que.pop();
        }
        if (!que.empty()) {
            right->value = que.front();
            parent->right = right;
            nodeQue.push(right);
            que.pop();
        }
    }
}

void print(stack<int> path) {
    stack<int> temp;
    bool first = true;
    while (!path.empty()) {
        temp.push(path.top());
        path.pop();
    }
    int last = temp.top(); temp.pop();
    int next;
    while (!temp.empty()) {
        next = temp.top();
        if (last < next) isMaxHeap = false;
        if (last > next) isMinHeap = false;
        if (first) {
            first = false;
            cout << last;
        } else
            cout << " " << last;
        temp.pop();
        last = next;
    }
    cout << " " << last << endl;
}

void travel(node root) {
    path.push(root->value);
    if (root->left == NULL && root->right == NULL) {
        print(path);
        path.pop();
        return;
    }
    if (root->right) travel(root->right);
    if (root->left) travel(root->left);
    path.pop();
}

int main() {
    int num, value;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> value;
        que.push(value);
    }
    buildTree();
    travel(root);
    if (isMaxHeap) cout << "Max Heap" << endl;
    else if (isMinHeap) cout << "Min Heap" << endl;
    else cout << "Not Heap" << endl;

    return 0;
}