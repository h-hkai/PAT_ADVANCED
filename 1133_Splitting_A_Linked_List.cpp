#include <bits/stdc++.h>

using namespace std;

struct Node {
    int address;
    int date;
    int next;
};

int main() {
    int first, n, k;
    cin >> first >> n >> k;
    vector<Node> v(100005), ans;
    int address, date, next;
    for (int i = 0; i < n; ++i) {
        cin >> address >> date >> next;
        v[address] = {address, date, next};
    }
    address = first;
    for (; address != -1; address = v[address].next)
        if (v[address].date < 0) ans.push_back(v[address]);

    address = first;
    for (; address != -1; address = v[address].next)
        if (v[address].date >= 0 && v[address].date <= k)
            ans.push_back(v[address]);
    address = first;
    for (; address != -1; address = v[address].next)
        if (v[address].date > k) ans.push_back(v[address]);
    printf("%05d %d", ans[0].address, ans[0].date);
    for (int i = 1; i < ans.size(); ++i) {
        printf(" %05d\n%05d %d", ans[i].address, ans[i].address, ans[i].date);
    }
    printf(" -1\n");
    return 0;
}