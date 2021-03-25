#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, d;
    cin >> n;
    while (n > 0) {
        cin >> d;
        string temp = "";
        int r = n;
        while (r > 0) {
            temp += to_string(r % d);
            r /= d;
        }
        int index = 0;
        for (int i = temp.size() - 1; i >= 0; --i)
            r += (temp[i] - '0') * pow(d, index++);
        if (isPrime(n) && isPrime(r)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        cin >> n;
    }

    return 0;
}