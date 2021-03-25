#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int ans, temp = 1;
    for (int i = 0; i < n; ++i) {
        if (v[i] <= i + 1) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}