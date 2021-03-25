#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    double p, r;
    scanf("%d%lf%lf", &n, &p, &r);
    vector<int> path(n);
    vector<pair<int, int> > product;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        if (k == 0) {
            int t;
            scanf("%d", &t);
            product.push_back({i, t});
        } else
            for (int j = 0; j < k; ++j) {
                int t;
                scanf("%d", &t);
                path[t] = i;
            }
    }
    double sum = 0.0;
    for (int i = 0; i < product.size(); ++i) {
        int id = product[i].first;
        int count = 0;
        while (id != 0) {
            id = path[id];
            count++;
        }
        sum += (pow(1 + r / 100.0, count) * p) * product[i].second;
    }

    printf("%.1lf\n", sum);

    return 0;
}