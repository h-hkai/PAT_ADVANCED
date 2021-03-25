#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, t;
    cin >> n;

    vector<int> req;

    int total = 0, pre = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t > pre) {
            total += (t - pre) * 6 + 5;
            pre = t;
        } else {
            total += (pre - t) * 4 + 5;
            pre = t;
        }
    }

    cout << total;

    return 0;
}