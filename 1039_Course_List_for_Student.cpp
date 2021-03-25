#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<string, vector<int> > courses;
    for (int i = 0; i < k; ++i) {
        int index, num;
        string name;
        cin >> index >> num;
        for (int j = 0; j < num; ++j) {
            cin >> name;
            courses[name].push_back(index);
        }
    }
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        sort(courses[name].begin(), courses[name].end());
        cout << name << " " << courses[name].size();
        for (int j : courses[name]) cout << " " << j;
        cout << endl;
    }

    return 0;
}