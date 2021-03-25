#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    vector<int> path(n, 0);
    vector<int> len(n, 0);
    vector<int> retailers;
    len[0] = 1;
    for (int i = 0; i < n; ++i) {
        int k, t;
        scanf("%d", &k);
        if (k == 0)
            retailers.push_back(i);
        else
            for (int j = 0; j < k; ++j) {
                scanf("%d", &t);
                path[t] = i;
                if (len[i] > 0) len[t] = len[i] + 1;
            }
    }
    int minn = INT_MAX;
    int ways = 1;
    for (int i : retailers) {
        int temp = i, count = 0, dummy;
        while (path[temp] != 0) {
            dummy = temp;
            temp = path[temp];
            if (len[temp] > 0) {
                count += len[temp];
                len[dummy] = len[temp] + 1;
                break;
            } else
                count++;
        }
        len[i] = count;
        if (len[i] < minn) {
            ways = 1;
            minn = len[i];
        } else if (len[i] == minn) {
            ways++;
        }
    }
    double ans = p;
    ans = pow(1 + r / 100.0, minn) * p;
    printf("%.4lf %d\n", ans, ways);
    return 0;
}
