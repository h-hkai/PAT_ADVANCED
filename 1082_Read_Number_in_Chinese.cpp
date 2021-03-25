#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    if (stoi(str) == 0) {
        cout << "ling" << endl;
        return 0;
    }
    stack<string> ans;
    bool isNegative = false;
    if (str[0] == '-') {
        str = str.substr(1);
        isNegative = true;
    }
    int index = str.length() - 1;
    string dummy[4] = {"+", "Shi", "Bai", "Qian"};
    string numInCn[10] = {"ling", "yi",  "er", "san", "si",
                          "wu",   "liu", "qi", "ba",  "jiu"};
    while (index >= 0) {
        bool notZero = false;
        for (int i = 0; i < 4 && index >= 0; ++i, --index) {
            if (str[index] == '0' && !notZero)
                continue;
            else {
                if (str[index] == '0') {
                    ans.push(numInCn[str[index] - '0']);
                } else {
                    if (i != 0) ans.push(dummy[i]);
                    ans.push(numInCn[str[index] - '0']);
                }
                notZero = true;
            }
        }
        notZero = false;
        if (index >= 0) ans.push("Wan");
        for (int i = 0; i < 4 && index >= 0; ++i, --index) {
            if (str[index] == '0' && !notZero)
                continue;
            else {
                if (str[index] == '0') {
                    ans.push(numInCn[str[index] - '0']);
                } else {
                    if (i != 0) ans.push(dummy[i]);
                    ans.push(numInCn[str[index] - '0']);
                }
                notZero = true;
            }
        }
        if (index >= 0) {
            ans.push("Yi");
            ans.push(numInCn[str[index] - '0']);
            --index;
        }
    }
    if (isNegative) {
        cout << "Fu";
        while (!ans.empty()) {
            cout << " " << ans.top();
            ans.pop();
        }
    } else {
        cout << ans.top();
        ans.pop();
        while (!ans.empty()) {
            cout << " " << ans.top();
            ans.pop();
        }
    }

    return 0;
}