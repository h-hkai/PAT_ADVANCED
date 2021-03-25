#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> minn(n), maxx(n), v(n, 0);
    int tempMax = -1;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] > tempMax) {
            maxx[i] = tempMax;
            tempMax = v[i];
        } else {
            maxx[i] = tempMax;
        }
    }
    int tempMin = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        if (v[i] < tempMin) {
            minn[i] = tempMin;
            tempMin = v[i];
        } else {
            minn[i] = tempMin;
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (v[i] > maxx[i] && v[i] < minn[i]) ans.push_back(v[i]);
    }
    sort(ans.begin(), ans.end());
    bool isFirst = true;
    cout << ans.size() << endl;
    for (int i : ans)
        if (isFirst) {
            cout << i;
            isFirst = false;
        } else {
            cout << " " << i;
        }
    cout << endl;
    return 0;
}