#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n;

    vector<int> v(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t > 0 && t <= n) v[t] = 1;
    }
    bool found = false;
    for (int i = 1; i <= n; ++i) {
        if (v[i] < 0) {
            cout << i << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << n + 1 << endl;

    return 0;
}