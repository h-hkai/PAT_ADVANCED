#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();
    string last, cur, temp;
    for (int i = 0; i < n; ++i) {
        if (i == 0)
            getline(cin, last);
        else {
            temp = "";
            getline(cin, cur);
            int len1 = cur.length() - 1;
            int len2 = last.length() - 1;
            while (len1 >= 0 && len2 >= 0) {
                if (cur[len1--] == last[len2]) {
                    temp = last[len2--] + temp;
                } else
                    break;
            }
            last = temp;
        }
    }
    if (last.length() == 0)
        cout << "nai" << endl;
    else {
        for (int i = 0; i < temp.length(); ++i) cout << temp[i];
        cout << endl;
    }
    return 0;
}