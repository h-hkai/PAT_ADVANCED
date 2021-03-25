#include <bits/stdc++.h>

using namespace std;

// bool cmp(string s1, string s2) {
//     return s1 < s2;
// }

int main() {
    int n;
    cin >> n;
    vector<string> v(n + 1);
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.begin() + n);
    v.push_back("999999999");
    string res;
    int cnt = 0, i = 0, j;
    while (cnt < n) {
        j = i + 1;
        while (used[j]) ++j;
        int len = v[i].length();
        if (v[i] == v[j].substr(0, len)) {
            if (v[j][0] < v[j][len]) {
                res += v[i];
                used[i] = true;
                while (used[i]) ++i;
            } else {
                res += v[j];
                used[j] = true;
            }
        } else {
            res += v[i];
            used[i] = true;
            while (used[i]) ++i;
        }
        cnt++;
    }
    int start = 0;
    while (res[start] == '0') start++;
    cout << res.substr(start) << endl;
    return 0;
}