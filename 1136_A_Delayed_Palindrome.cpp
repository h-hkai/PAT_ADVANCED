#include <bits/stdc++.h>

using namespace std;

string addFunction(string num1, string num2) {
    int carry = 0, n1, n2, temp;
    int len = num1.length();
    reverse(num2.begin(), num2.end());
    string ans = "";
    while (len >= 1) {
        len--;
        n1 = num1[len] - '0';
        n2 = num2[len] - '0';
        temp = n1 + n2 + carry;
        carry = temp / 10;
        ans = to_string(temp % 10) + ans;
    }
    if (carry == 1) ans = to_string(carry) + ans;
    return ans;
}

bool isPalindrome(string str) {
    int i = 0, j = str.length() - 1;
    while (i < j) {
        if (str[i++] != str[j--]) return false;
    }
    return true;
}

int main() {
    string str, sum, temp;
    cin >> str;
    for (int i = 0; i < 10; ++i) {
        if (isPalindrome(str)) {
            cout << str << " is a palindromic number." << endl;
            break;
        }
        temp = str;
        sum = addFunction(str, str);
        reverse(temp.begin(), temp.end());
        cout << str << " + " << temp << " = " << sum << endl;
        if (i == 9) cout << "Not found in 10 iterations." << endl;
        str = sum;
    }

    return 0;
}