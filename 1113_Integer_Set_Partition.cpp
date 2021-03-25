#include <bits/stdc++.h>

using namespace std;

int sum(vector<int> v, int s, int e) {
    int sum = 0;
    for (int i = s; i <= e; ++i) {
        sum += v[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int mid = n / 2;
    int preSum = sum(v, 0, mid - 1);
    int postSum = sum(v, mid, n - 1);
    if (v.size() % 2 == 0) {
        cout << 0 << " " << postSum - preSum << endl;
    } else {
        cout << 1 << " " << postSum - preSum << endl;
    }
    return 0;
}