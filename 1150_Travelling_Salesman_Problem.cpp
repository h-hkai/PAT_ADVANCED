#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int inf = 0x7fffffff;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > martix(n+1, vector<int>(n+1, -1));
    int c1, c2, d;
    for (int i = 0; i < m; ++i) {
        cin >> c1 >> c2 >> d;
        martix[c1][c2] = martix[c2][c1] = d;
    }

    set<int> s;
    int shortestDist = inf, sdIndex;
    int k, t, index = 1, dis, start;
    bool isTSSimpleCycle, flag;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> t >> start;
        flag = true;
        isTSSimpleCycle = true;
        dis = 0, c1 = start;
        s.clear();
        for (int j = 1; j < t; ++j) {
            cin >> c2;
            if (s.find(c2) != s.end()) {
                isTSSimpleCycle = false;
            } else {
                s.insert(c2);
            }
            if (martix[c1][c2] == -1) {
                flag = false;
            } else {
                dis += martix[c1][c2];
            }
            c1 = c2;
        }
        if (c1 == start && flag) {
            if (isTSSimpleCycle && s.size() == n) {
                if (shortestDist > dis) {
                    sdIndex = index;
                    shortestDist = dis;
                }                
                cout << "Path " << index << ": " << dis << " (TS simple cycle)" << endl;
            } else if (s.size() == n){
                if (shortestDist > dis) {
                    sdIndex = index;
                    shortestDist = dis;
                }
                cout << "Path " << index << ": " << dis << " (TS cycle)" << endl;
            } else {
                cout << "Path " << index << ": " << dis << " (Not a TS cycle)" << endl;
            }
        } else {
            if (flag) {
                cout << "Path " << index << ": " << dis << " (Not a TS cycle)" << endl;
            } else {
                cout << "Path " << index << ": NA" << " (Not a TS cycle)" << endl;
            }
        }
        index++;
    }
    cout << "Shortest Dist(" << sdIndex << ") = " << shortestDist << endl;
    return 0;
}