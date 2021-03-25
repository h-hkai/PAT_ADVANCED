#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> sum;

void BS(int i, int& j, int& tempSum) {
    int left = i, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (sum[mid] - sum[i - 1] >= m)
            right = mid;
        else
            left = mid + 1;
    }
    j = right;
    tempSum = sum[j] - sum[i - 1];
}

int main() {
    cin >> n >> m;
    sum.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    int minans = sum[n];
    vector<pair<int, int> > res;
    for (int i = 1; i <= n; ++i) {
        int j, tempSum;
        BS(i, j, tempSum);
        if (tempSum > minans) continue;
        if (tempSum >= m) {
            if (tempSum < minans) {
                res.clear();
                minans = tempSum;
            }
            res.push_back({i, j});
        }
    }

    for (auto it : res) cout << it.first << "-" << it.second << endl;

    return 0;
}