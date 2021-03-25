#include <bits/stdc++.h>

using namespace std;

int fa[1005];

int findFather(int x) {
    int a = x;
    while (x != fa[x]) x = fa[x];
    while (a != fa[a]) {
        int z = a;
        a = fa[a];
        fa[z] = x;
    }
    return x;
}

void Union(int x, int y) {
    int faX = findFather(x);
    int faY = findFather(y);
    if (faX > faY)
        fa[faX] = faY;
    else
        fa[faY] = faX;
}

int main() {
    int n, k;
    cin >> n;
    getchar();
    int num;
    vector<int> people;
    for (int i = 0; i < 1005; ++i) fa[i] = i;
    for (int i = 0; i < n; ++i) {
        string temp, dummy;
        getline(cin, temp);
        int pos = temp.find(':');
        int len = stoi(temp.substr(0, pos));
        dummy = temp.substr(pos + 2);
        vector<int> hobbies;
        string str = "";
        for (int j = 0; j <= dummy.size(); ++j) {
            if (dummy[j] == ' ' || dummy[j] == '\0') {
                hobbies.push_back(stoi(str));
                str = "";
            } else {
                str += dummy[j];
            }
        }
        for (int j = 1; j < hobbies.size(); ++j) {
            Union(hobbies[0], hobbies[j]);
        }
        people.push_back(hobbies[0]);
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int r = findFather(people[i]);
        mp[r]++;
    }
    vector<int> ans;
    for (auto it : mp) ans.push_back(it.second);
    sort(ans.begin(), ans.end(), greater<int>());
    cout << ans.size() << endl;
    cout << ans[0];
    for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
    cout << endl;
    return 0;
}