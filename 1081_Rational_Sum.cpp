#include <bits/stdc++.h>

using namespace std;

struct Number {
    int sign;
    long long numerator;
    long long denominator;
};

long long gcdFun(long long x, long long y) {
    if (x == 0 || y == 0)
        return x == 0 ? y : x;
    else
        return x > y ? gcdFun(y, x % y) : gcdFun(x, y % x);
}

int main() {
    int n;
    cin >> n;
    int gcd = 1;
    stack<Number> s;
    for (int i = 0; i < n; ++i) {
        string str;
        int sign = 1;
        long long numerator, denominator;
        cin >> str;
        if (str[0] == '-') {
            sign = -1;
            str = str.substr(1);
        }
        int pos = str.find('/');
        numerator = stoll(str.substr(0, pos));
        denominator = stoll(str.substr(pos + 1));
        int gcd = gcdFun(numerator, denominator);
        if (gcd == 0) continue;
        s.push({sign, numerator / gcd, denominator / gcd});
    }
    while (s.size() > 1) {
        Number num1 = s.top();
        s.pop();
        Number num2 = s.top();
        s.pop();
        long long gcd = gcdFun(num1.denominator, num2.denominator);
        long long lcm = num1.denominator * num2.denominator / gcd;
        long long mult1 = lcm / num1.denominator;
        long long mult2 = lcm / num2.denominator;
        long long sumNumerator = num1.sign * num1.numerator * mult1 +
                                 num2.sign * num2.numerator * mult2;
        int sign = 1;
        if (sumNumerator < 0) {
            sign = -1;
            sumNumerator = abs(sumNumerator);
        }
        gcd = gcdFun(sumNumerator, lcm);
        s.push({sign, sumNumerator / gcd, lcm / gcd});
    }
    Number ans = s.top();
    long long integer = ans.numerator / ans.denominator;
    long long fractional = ans.numerator % ans.denominator;
    if (integer != 0 && fractional != 0) {
        cout << integer << " " << fractional << "/" << ans.denominator << endl;
    } else if (integer != 0) {
        cout << integer << endl;
    } else if (fractional != 0) {
        cout << fractional << "/" << ans.denominator << endl;
    } else
        cout << "0" << endl;

    return 0;
}