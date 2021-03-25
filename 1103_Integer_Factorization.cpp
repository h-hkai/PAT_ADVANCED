#include <bits/stdc++.h>

using namespace std;

int n, k, p;
vector<int> v, ans, tempAns;
int maxFacSum = -1;

void init() {
    int temp = 0, index = 1;
    while (temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}

void DFS(int index, int tempSum, int tempK, int facSum) {
    if (tempK == k) {
        if (tempSum == n && facSum > maxFacSum) {
            ans = tempAns;
            maxFacSum = facSum;
        }
        return;
    }
    while (index >= 1) {
        if (tempSum + v[index] <= n) {
            tempAns[tempK] = index;
            DFS(index, tempSum + v[index], tempK + 1, facSum + index);
        }
        if (index == 1) return;
        index--;
    }
}

int main() {
    cin >> n >> k >> p;
    init();
    tempAns.resize(k);
    DFS(v.size() - 1, 0, 0, 0);
    if (maxFacSum == -1)
        cout << "Impossible" << endl;
    else {
        cout << n << " = ";
        for (int i = 0; i < ans.size(); ++i)
            if (i == 0)
                cout << ans[i] << "^" << p;
            else
                cout << " + " << ans[i] << "^" << p;
        cout << endl;
    }
    return 0;
}