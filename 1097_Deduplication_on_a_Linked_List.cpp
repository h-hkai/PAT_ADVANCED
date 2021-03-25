#include<iostream>
#include<map>
#include<set>
#include<cmath>
#include<string>
#include<cstdio>

using namespace std;

typedef struct Node *node;

struct Node {
    int addr;
    int key;
    int next;
    node nextnode;
    Node(int s1, int k, int s2) : addr(s1), key(k), next(s2), nextnode(NULL) {}
};

int main() {
    int n;
    int start;
    scanf("%d%d", &start, &n);
    node Head1 = (node)malloc(sizeof(struct Node));
    node Head2 = (node)malloc(sizeof(struct Node));

    node prt1, prt2, pre;
    prt1 = Head1;
    prt2 = Head2;

    map<int, node> m;
    set<int> s;
    node num, temp;

    for (int i = 0; i < n; ++i) {
        int key;
        int addr, next;
        scanf("%d%d%d", &addr, &key, &next);
        num = new Node(addr, key, next);
        m.insert({addr, num});
    }

    for (int i = 0; i < n; ++i) {
        temp = m.find(start)->second;
        prt1->nextnode = temp;
        prt1 = prt1->nextnode;
        start = prt1->next;
    }

    prt1 = Head1->nextnode;
    pre = Head1;

    while (prt1) {
        int k = abs(prt1->key);
        if (s.find(k) == s.end()) {
            prt1 = prt1->nextnode;
            pre = pre->nextnode;
            s.insert(k);
        } else {
            prt2->nextnode = prt1;
            prt2 = prt2->nextnode;
            pre->nextnode = prt1->nextnode;
            prt1 = prt1->nextnode;
        }
    }

    prt1 = Head1->nextnode;
    prt2 = Head2->nextnode;
    while (prt1) {
        if (prt1->nextnode == NULL)
            printf("%05d %d -1\n", prt1->addr, prt1->key);
        else
            printf("%05d %d %05d\n", prt1->addr, prt1->key, prt1->nextnode->addr);
        prt1 = prt1->nextnode;
    } 

    while (prt2) {
        if (prt2->nextnode == NULL)
            printf("%05d %d -1\n", prt2->addr, prt2->key);
        else 
            printf("%05d %d %05d\n", prt2->addr, prt2->key, prt2->nextnode->addr);
        prt2 = prt2->nextnode;
    }
 
    return 0;
}