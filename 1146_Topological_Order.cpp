#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int s, e;
    vector<vector<int> > grap(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
        cin >> s >> e;
        grap[s][e] = 1;
    }

    int k, t;
    cin >> k;
    vector<int> ans, temp;
    vector<vector<int> > dummy;
    for (int i = 0; i < k; ++i) {
        dummy = grap;
        temp.clear();
        for (int j = 0; j < n; ++j) {
            cin >> t;
            temp.push_back(t);
        }
        bool flag = false;
        for (int j = 0; j < n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (dummy[k][temp[j]] == 1) {
                    flag = true;
                    ans.push_back(i);
                    break;
                } else
                    dummy[temp[j]][k] = 0;
            }
            if (flag) break;
        }
    }
    cout << ans[0];
    for (int i = 1; i < ans.size(); ++i) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}