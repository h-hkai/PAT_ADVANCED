#include <bits/stdc++.h>

using namespace std;

int main() {
    int nc, np;
    cin >> nc;
    vector<int> coupons(nc);
    for (int i = 0; i < nc; ++i) cin >> coupons[i];
    sort(coupons.begin(), coupons.end(), greater<int>());
    cin >> np;
    vector<int> products(np);
    for (int i = 0; i < np; ++i) cin >> products[i];
    sort(products.begin(), products.end(), greater<int>());
    vector<bool> couponsUsed(nc + 1, false);
    vector<bool> productsUsed(np + 1, false);
    int i = 0, j = 0, res = 0;
    while (i < nc && j < np) {
        if (coupons[i] * products[j] > 0) {
            couponsUsed[i] = true;
            productsUsed[j] = true;
            res += coupons[i++] * products[j++];
        } else
            break;
    }
    if (i == nc || j == np)
        cout << res << endl;
    else {
        i = nc - 1;
        j = np - 1;
        while (i >= 0 && j >= 0) {
            if (couponsUsed[i] || productsUsed[j]) break;
            if (coupons[i] * products[j] > 0) {
                res += coupons[i--] * products[j--];
            } else
                break;
        }
        cout << res << endl;
    }
    return 0;
}