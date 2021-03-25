#include <bits/stdc++.h>

using namespace std;

int main() {
    int n1, n2, t;
    scanf("%d", &n1);
    vector<int> v(400005);
    for (int i = 0; i < n1; ++i) scanf("%d", &v[i]);
    scanf("%d", &n2);
    for (int i = n1; i < n2 + n1; ++i) scanf("%d", &v[i]);
    int mid = (n1 + n2 + 1) / 2;
    sort(v.begin(), v.begin() + n1 + n2);
    cout << v[mid - 1] << endl;
    return 0;
}