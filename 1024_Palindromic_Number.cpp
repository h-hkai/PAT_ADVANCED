#include <bits/stdc++.h>

using namespace std;

string s;

void add(string r) {
    int carry = 0;
    int len = r.length();
    for (int i = 0; i < len; ++i) {
        s[i] = s[i] + r[i] + carry - '0';
        carry = 0;
        if (s[i] > '9') {
            carry = 1;
            s[i] -= 10;
        }
    }
    if (carry == 1) s += '1';
    reverse(s.begin(), s.end());
}

int main() {
    int k, step;
    cin >> s >> k;
    for (step = 0; step < k; ++step) {
        string r = s;
        reverse(r.begin(), r.end());
        if (r == s || step == k) break;
        add(r);
    }
    cout << s << endl << step << endl;
    return 0;
}
