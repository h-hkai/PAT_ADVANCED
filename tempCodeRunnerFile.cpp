#include <bits/stdc++.h>

using namespace std;

const int maxsize = 1005;

typedef struct BTNode {
    int val;
    BTNode *left;
    BTNode *right;
};

typedef struct {
    BTNode *p;
    int revisited;
} SNode;

void PostOrder2(BTNode *root) {
    SNode sn;
    BTNode *pt = root;
    stack<SNode> S;
    while (pt) {
        S.push({pt, 0});
        pt = pt->left;
    }
    while (!S.empty()) {
        sn = S.top();
        if (sn.p->right == NULL || sn.revisited == 1) {
            S.pop();
            cout << pt->val << " ";
        } else {
            sn.revisited = 1;
            pt = sn.p->right;
            while (pt != NULL) {
                S.push({pt, 0});
                pt = pt->left;
            }
        }
    }
}

void InOrder2(BTNode *root) {
    BTNode *p = root;
    stack<BTNode *> S;
    while (p != NULL || !S.empty()) {
        if (p) {  // 找到树中最左边的那个结点，并将路径中经过的结点依次压入栈中
            S.push(p);
            p = p->left;
        } else {  // 如果该节点为空则输出其双亲结点
            S.pop();
            p = S.top();
            cout << p->val << " ";
            p = p->right;  // 访问双亲结点的右孩子
        }
    }
}