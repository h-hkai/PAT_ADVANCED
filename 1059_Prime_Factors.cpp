#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n == 1) {
        cout << n << "=" << n;
        return 0;
    } else {
        cout << n << "=";
    }
    vector<int> prime(50000, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i < 50000; ++i) {
        for (int j = 2; i * j < 50000; ++j) {
            prime[i * j] = 0;
        }
    }
    bool isFirst = true;
    int temp = n;
    for (int i = 2; i < 50000; ++i) {
        int cnt = 0;
        bool found = false;
        while (prime[i] == 1 && temp % i == 0) {
            temp /= i;
            cnt++;
            found = true;
        }
        if (found) {
            if (isFirst) {
                cout << i;
                if (cnt > 1) cout << "^" << cnt;
                isFirst = false;
            } else {
                cout << "*" << i;
                if (cnt > 1) cout << "^" << cnt;
            }
        }
    }
    if (temp > 1) cout << (isFirst ? "" : "*") << temp << endl;
    return 0;
}