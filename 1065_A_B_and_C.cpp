#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long a, b, c, sum;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b >> c;
        sum = a + b;
        if (a > 0 && b > 0 && sum < 0)
            cout << "Case #" << i << ": true" << endl;
        else if (a < 0 && b < 0 && sum > 0)
            cout << "Case #" << i << ": false" << endl;
        else {
            if (sum > c)
                cout << "Case #" << i << ": true" << endl;
            else
                cout << "Case #" << i << ": false" << endl;
        }
    }
    return 0;
}