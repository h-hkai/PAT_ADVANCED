#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n;

    set<int> s;
    int ans;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        ans = 0;
        while (t) {
            ans += t % 10;
            t /= 10;
        }
        s.insert(ans);
    }
    cout << s.size() << endl;
    bool isFirst = true;
    for (int i : s) {
        if (isFirst) {
            cout << i;
            isFirst = false;
        } else {
            cout << " " << i;
        }
    }
    cout << endl;
    return 0;
}