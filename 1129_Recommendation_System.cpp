#include <bits/stdc++.h>

using namespace std;

struct Node {
    int num;
    int index;
    bool operator<(const Node& a) const {
        return a.num == num ? a.index > index : a.num < num;
    }
};

int main() {
    int n, k, t, cnt;
    cin >> n >> k;
    vector<int> v(n + 1, 0);
    set<Node> s;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        cnt = 0;
        if (i != 1) {
            cout << t << ":";
            for (auto it : s)
                if (cnt++ < k)
                    cout << " " << it.index;
                else
                    break;
            cout << endl;
        }
        auto it = s.find(Node{v[t], t});
        if (it != s.end()) s.erase(it);
        v[t]++;
        s.insert(Node{v[t], t});
    }

    return 0;
}