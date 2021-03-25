#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long a, b, c;
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        int len = str.length();
        a = stoll(str.substr(0, len / 2));
        b = stoll(str.substr(len / 2));
        c = stoll(str);
        if (a == 0 || b == 0 || c == 0)
            cout << "No" << endl;
        else {
            if (c % (a * b) == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}