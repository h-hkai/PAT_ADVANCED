#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dist(n + 1, 0);
    vector<int> sum1(n + 1, 0);
    vector<int> sum2(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> dist[i];
    for (int i = 1; i <= n; ++i) sum1[i] = sum1[i - 1] + dist[i - 1];
    for (int i = n; i >= 1; --i) {
        if (i == n)
            sum2[i] = dist[i];
        else if (i == 1)
            sum2[i] = 0;
        else
            sum2[i] = sum2[i + 1] + dist[i];
    }
    int m, a, b;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if (a < b) swap(a, b);
        int temp = min(sum1[a] - sum1[b], sum1[b] + sum2[a]);
        cout << temp << endl;
    }
    return 0;
}