#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n;
    vector<int> index(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> t;
        index[t] = i;
    }
    int count = 0;
    for (int i = 1; i < n; ++i) {
        if (i != index[i]) {
            while (index[0] != 0) {
                swap(index[0], index[index[0]]);
                count++;
            }
            if (i != index[i]) {
                swap(index[0], index[i]);
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}