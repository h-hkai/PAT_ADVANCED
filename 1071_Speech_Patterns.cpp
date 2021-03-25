#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int main() {
    string str;
    getline(cin, str);
    string temp;
    map<string, int> m;
    for (int i = 0; i < str.length(); ++i) {
        if (isalnum(str[i])) {
            temp += (char)tolower(str[i]);
        } else {
            if (temp.length() > 0) m[temp]++;
            temp = "";
        }
    }
    vector<pair<int, string> > v;
    for (auto it : m) {
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].second << " " << v[0].first << endl;
    return 0;
}