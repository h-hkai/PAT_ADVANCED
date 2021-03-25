#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

int main() {
    int n, m, k, t;
    cin >> n >> m;

    int g1, g2;
    set<int> seen;
    map<int, set<int> >  mp;
    set<int> shapped;
    for (int i = 0; i < n; ++i) {
        cin >> g1 >> g2;
        seen.insert(g1);
        seen.insert(g2);
        mp[g1].insert(g2);
        mp[g2].insert(g1);
    }
    for (int i = 0; i < m; ++i) {
        cin >> k;
        shapped.clear();
        bool flag = false;
        for (int j = 0; j < k; ++j) {
            cin >> t;
            if (seen.find(t) != seen.end())
                shapped.insert(t);
        }
        for (auto good : shapped) {
            for (auto it : mp[good]) {
                if (shapped.find(it) != shapped.end()) {
                    cout << "No" << endl;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) cout << "Yes" << endl;
    }

    return 0;
}