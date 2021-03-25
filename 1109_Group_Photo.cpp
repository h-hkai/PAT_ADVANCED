#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<string, int> > people;
    for (int i = 0; i < n; ++i) {
        string name;
        int height;
        cin >> name >> height;
        people.push_back({name, height});
    }
    int row = n / k;
    int mod = n % k;
    sort(people.begin(), people.end(),
         [](pair<string, int> a, pair<string, int> b) -> bool {
             if (a.second == b.second)
                 return a.first < b.first;
             else
                 return a.second > b.second;
         });

    vector<vector<pair<string, int> > > ans;
    vector<pair<string, int> > temp, dummy;
    temp.assign(people.begin(), people.begin() + row + mod);
    dummy = temp;
    int pos = temp.size() / 2;
    dummy[pos] = temp[0];
    int index = 1;
    for (int i = 1; index < temp.size(); ++i) {
        if (pos - i >= 0) dummy[pos - i] = temp[index++];
        if (pos + i < temp.size()) dummy[pos + i] = temp[index++];
    }
    cout << dummy[0].first;
    for (int i = 1; i < dummy.size(); ++i) cout << " " << dummy[i].first;
    cout << endl;
    for (int i = 1; i < row; ++i) {
        for (int j = i * row + 1; j < (i + 1) * row + 1; ++j)
            temp.push_back(people[j]);
        dummy = temp;
        pos = temp.size() / 2;
        dummy[pos] = temp[0];
        index = 1;
        for (int j = 1; index < temp.size(); ++j) {
            if (pos - j >= 0) dummy[pos - j] = temp[index++];
            if (pos + j < temp.size()) dummy[pos + j] = temp[index++];
        }
        cout << dummy[0].first;
        for (int j = 1; j < dummy.size(); ++j) cout << " " << dummy[j].first;
        cout << endl;
    }

    return 0;
}