#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    sort(coins.begin(), coins.end());
    int i = 0, j = coins.size() - 1;
    while (i < j) {
        if (coins[i] + coins[j] > m)
            j--;
        else if (coins[i] + coins[j] < m)
            i++;
        else
            break;
    }
    if (i >= j)
        cout << "No Solution" << endl;
    else
        cout << coins[i] << " " << coins[j] << endl;
    return 0;
}