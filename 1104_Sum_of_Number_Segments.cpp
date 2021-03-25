#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    double ans = 0.0, temp;

    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        ans = ans + temp * i * (n - i + 1);
    }

    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}