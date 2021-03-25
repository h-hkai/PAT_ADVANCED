#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m;
    vector<pair<int, int> > v;
    int v1, v2;
    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2;
        v.push_back({v1, v2});
    }
    set<int> s;
    vector<int> color;
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        s.clear();
        color.clear();
        for (int j = 0; j < n; ++j) {
            cin >> c;
            color.push_back(c);
            s.insert(c);            
        }
        for (int j = 0; j < v.size(); ++j) {
            v1 = v[j].first;
            v2 = v[j].second;
            if (color[v1] == color[v2]) {
                cout << "No" << endl;
                break;
            }
            if (j == v.size()-1) {
                cout << s.size() << "-coloring" << endl;
            }
        }
    }
    return 0;
}