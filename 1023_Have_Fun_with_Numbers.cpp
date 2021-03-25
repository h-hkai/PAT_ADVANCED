#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length();
    int carry = 0;
    map<int, int> m;
    for (int i = 0; i < s.length(); ++i) m[s[i] - '0']++;
    for (int i = len - 1; i >= 0; --i) {
        s[i] += s[i] + carry - '0';
        carry = 0;
        if (s[i] > '9') {
            s[i] -= 10;
            carry = 1;
        }
    }
    if (carry == 1) s = '1' + s;
    int flag = 0;
    for (int i = 0; i < s.length(); ++i)
        if (m[s[i] - '0'] > 0)
            m[s[i] - '0']--;
        else
            flag = 1;
    if (flag == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << s << endl;
    return 0;
}