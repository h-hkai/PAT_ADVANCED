#include <bits/stdc++.h>

using namespace std;

struct Mooncake {
    double amount = 0.0;
    double profit = 0.0;
    double price = 0.0;
};

bool cmp(Mooncake a, Mooncake b) { return a.price > b.price; }

int main() {
    int n, total;
    cin >> n >> total;
    vector<Mooncake> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].amount;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].profit;
        v[i].price = v[i].profit / v[i].amount;
    }
    sort(v.begin(), v.end(), cmp);
    double sumProfit = 0.0;
    for (int i = 0; i < n; ++i) {
        if (total >= v[i].amount) {
            sumProfit += v[i].profit;
            total -= v[i].amount;
        } else {
            sumProfit += v[i].profit * ((double)total / v[i].amount);
            break;
        }
    }
    cout << fixed << setprecision(2) << sumProfit << endl;
    return 0;
}