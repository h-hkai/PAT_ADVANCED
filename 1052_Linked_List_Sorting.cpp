#include <bits/stdc++.h>

using namespace std;

struct Node {
    int address;
    int val;
    int next;
};

bool cmp(Node a, Node b) { return a.val < b.val; }

int main() {
    int n, head;
    cin >> n >> head;
    map<int, Node> mp;
    for (int i = 0; i < n; ++i) {
        int address, val, next;
        cin >> address >> val >> next;
        mp[address] = {address, val, next};
    }

    int cur = head;
    vector<Node> link;
    while (cur != -1) {
        if (mp.find(cur) != mp.end()) {
            link.push_back(mp[cur]);
            cur = mp[cur].next;
        }
    }
    sort(link.begin(), link.end(), cmp);
    int len = link.size();
    if (len == 0)
        printf("0 -1\n");
    else
        printf("%d %05d\n", len, link[0].address);
    for (int i = 0; i < len - 1; ++i) {
        printf("%05d %d %05d\n", link[i].address, link[i].val,
               link[i + 1].address);
    }
    if (len > 0)
        printf("%05d %d -1\n", link[len - 1].address, link[len - 1].val);
    return 0;
}