#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, b, t;
    cin >> n >> b;
    vector<int> v;
    while (n != 0) {
        t = n % b;
        v.push_back(t);
        n /= b;
    }
    if (v.size() == 0) {
        cout << "Yes" << endl;
        cout << "0";
        return 0;
    }
    int l = 0, r = v.size() - 1;
    bool isPalindromic = true;
    while (l <= r) {
        if (v[l] != v[r]) {
            isPalindromic = false;
            break;
        }
        l++;
        r--;
    }
    reverse(v.begin(), v.end());
    if (isPalindromic) {
        cout << "Yes" << endl;
        cout << v[0];
        for (int i = 1; i < v.size(); ++i) {
            cout << " " << v[i];
        }
    } else {
        cout << "No" << endl;
        cout << v[0];
        for (int i = 1; i < v.size(); ++i) {
            cout << " " << v[i];
        }
    }

    return 0;
}