#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool cmp(pair<string, string> x, pair<string, string> y) {
    if (abs(stoi(x.first)) != abs(stoi(y.first)))
        return abs(stoi(x.first)) < abs(stoi(y.first));
    else
        return abs(stoi(x.second)) < abs(stoi(y.second));
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int> > grap(N + 1, vector<int>(N + 1, -1));
    unordered_map<string, int> umap;
    unordered_map<int, string> convert;
    int index = 0;
    string f1, f2;
    for (int i = 0; i < M; ++i) {
        cin >> f1 >> f2;
        if (umap.find(f1) == umap.end()) {
            convert[index] = f1;
            umap[f1] = index++;
        }
        if (umap.find(f2) == umap.end()) {
            convert[index] = f2;
            umap[f2] = index++;
        }
        grap[umap[f1]][umap[f2]] = 1;
        grap[umap[f2]][umap[f1]] = 1;
    }

    int k;
    cin >> k;
    string q1, q2;
    vector<int> frends;
    vector<pair<string, string> > v;
    for (int i = 0; i < k; ++i) {
        cin >> q1 >> q2;
        if (umap.find(q1) == umap.end() || umap.find(q2) == umap.end()) {
            cout << 0 << endl;
            continue;
        }
        v.clear();
        frends.clear();
        for (int j = 0; j < N; ++j)
            if (grap[umap[q1]][j] == 1 && stoi(q1) * stoi(convert[j]) > 0 &&
                j != umap[q2]) {
                frends.push_back(j);
            }
        for (int j = 0; j < N; ++j) {
            if (grap[umap[q2]][j] == 1 && stoi(q2) * stoi(convert[j]) > 0 &&
                j != umap[q1]) {
                for (int k = 0; k < frends.size(); ++k) {
                    if (grap[frends[k]][j] == 1) {
                        v.push_back({convert[frends[k]], convert[j]});
                    }
                }
            }
        }
        cout << v.size() << endl;
        sort(v.begin(), v.end(), cmp);
        for (int j = 0; j < v.size(); ++j) {
            if (v[j].first[0] == '-') v[j].first = v[j].first.substr(1);
            if (v[j].second[0] == '-') v[j].second = v[j].second.substr(1);
            cout << v[j].first << " " << v[j].second << endl;
        }
    }

    return 0;
}