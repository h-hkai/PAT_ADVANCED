#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    int p1, p2, temp, ans = 1;
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        p1 = i;
        p2 = i + 1;
        temp = 0;
        while (p1 >= 0 && p2 < len) {
            if (str[p1--] == str[p2++])
                temp += 2;
            else
                break;
        }
        if (temp > ans) ans = temp;
    }
    for (int i = 0; i < len; ++i) {
        p1 = p2 = i;
        temp = -1;
        while (p1 >= 0 && p2 < len) {
            if (str[p1--] == str[p2++])
                temp += 2;
            else
                break;
        }
        if (temp > ans) ans = temp;
    }
    cout << ans << endl;
    return 0;
}