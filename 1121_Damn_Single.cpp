#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<pair<int, int> > v;
    int p1, p2;
    for (int i = 0; i < n; ++i) {
        cin >> p1 >> p2;
        v.push_back({p1, p2});
    }
    cin >> m;
    int p;
    set<int> s;
    while (m--) {
        cin >> p;
        s.insert(p);
    }
    for (int i = 0; i < n; ++i) {
        auto it1 = s.find(v[i].first);
        auto it2 = s.find(v[i].second);
        if (it1 != s.end() && it2 != s.end()) {
            s.erase(it1);
            s.erase(it2);
        }
    }
    cout << s.size() << endl;
    bool isFirst = true;
    for (int i : s) {
        if (isFirst) {
            printf("%04d", i);
            isFirst = false;
        } else {
            printf(" %04d", i);
        }
    }
    return 0;
}