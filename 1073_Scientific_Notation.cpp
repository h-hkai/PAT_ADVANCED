#include <bits/stdc++.h>

using namespace std;

int main() {
    string in;
    cin >> in;
    if (in[0] == '-') cout << '-';
    int pos = in.find('E');
    string coef = in.substr(1, pos - 1);
    string exp = in.substr(pos + 2);
    int e = stoi(exp);
    int c = stoi(coef);
    int len = coef.length();
    if (in[pos + 1] == '+') {
        if (len - 2 > e) {
            cout << coef[0];
            for (int i = 2; i < len; ++i) {
                if (i == e + 2) cout << '.';
                cout << coef[i];
            }
            cout << endl;
        } else {
            cout << coef[0];
            for (int i = 2; i < len; ++i) cout << coef[i];
            for (int i = 0; i < e - len + 2; ++i) cout << '0';
        }
    } else {
        if (e == 0) cout << 1 << endl;
        for (int i = 0; i < e; ++i) {
            cout << '0';
            if (i == 0) cout << '.';
        }
        cout << coef[0];
        for (int i = 2; i < len; ++i) cout << coef[i];
        cout << endl;
    }
    return 0;
}