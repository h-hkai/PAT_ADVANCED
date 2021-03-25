#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool isClique(vector<int>& v, vector<vector<int> >& grap) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (grap[v[i]][v[j]] == -1) return false;
        }
    }
    return true;
}

bool isMaxClique(vector<int>& v, vector<vector<int> >& grap) {
    set<int> s(v.begin(), v.end());
    for (int i = 1; i < grap.size(); ++i) {
        bool isMax = false;
        if (s.find(i) == s.end()) {
            for (int j = 0; j < v.size(); ++j) {
                if (grap[i][v[j]] == -1) {
                    isMax = true;
                    break;
                }
            }
            if (!isMax) return false;
        }
    }
    return true;
}

int main() {
    int Nv, Ne;
    cin >> Nv >> Ne;

    int v1, v2;
    vector<vector<int> > grap(Nv + 1, vector<int>(Nv + 1, -1));
    for (int i = 0; i < Ne; ++i) {
        cin >> v1 >> v2;
        grap[v1][v2] = grap[v2][v1] = 1;
    }
    int n, k, t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        vector<int> v(k, 0);
        for (int j = 0; j < k; ++j) {
            cin >> v[j];
        }
        if (k == 1) {
            cout << "Yes" << endl;
            continue;
        }
        if (isClique(v, grap)) {
            if (isMaxClique(v, grap)) {
                cout << "Yes" << endl;
            } else {
                cout << "Not Maximal" << endl;
            }
        } else {
            cout << "Not a Clique" << endl;
        }
    }

    return 0;
}