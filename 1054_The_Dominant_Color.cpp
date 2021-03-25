#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    string str;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> str;
            mp[str]++;
        }
    }
    int maxn = -1;
    for (auto it : mp) {
        if (it.second > maxn) {
            maxn = it.second;
            str = it.first;
        }
    }
    cout << str << endl;
    return 0;
}