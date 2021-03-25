#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string test;
    cin >> n >> test;
    int len = test.length();
    set<int> broken, well;
    string possible = "";
    for (int i = 0; i < len; ++i) {
        bool isBroken = true;
        if (i + n > len) {
            well.insert(test[i]);
            continue;
        }
        for (int j = i + 1; j < i + n && j < len; ++j) {
            if (test[j] != test[j - 1]) {
                well.insert(test[i]);
                isBroken = false;
                break;
            }
        }
        if (isBroken) i += n - 1;
    }
    for (int i = 0; i < len; ++i) {
        if (well.find(test[i]) == well.end()) {
            if (broken.find(test[i]) == broken.end()) possible += test[i];
            broken.insert(test[i]);
            i += n - 1;
        }
    }
    cout << possible << endl;
    string ans = "";
    for (int i = 0; i < len; ++i) {
        if (broken.find(test[i]) == broken.end())
            ans += test[i];
        else {
            ans += test[i];
            i += n - 1;
        }
    }
    cout << ans << endl;
    return 0;
}