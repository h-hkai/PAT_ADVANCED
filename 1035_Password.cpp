#include <bits/stdc++.h>

using namespace std;

struct User {
    string name;
    string password;
};

int main() {
    int n;
    cin >> n;
    map<char, char> mp;
    mp['1'] = '@';
    mp['0'] = '%';
    mp['l'] = 'L';
    mp['O'] = 'o';
    vector<User> res;
    for (int i = 0; i < n; ++i) {
        string name, password;
        cin >> name >> password;
        bool found = false;
        for (int j = 0; j < password.length(); ++j) {
            if (mp.find(password[j]) != mp.end()) {
                password[j] = mp[password[j]];
                found = true;
            }
        }
        if (found) res.push_back({name, password});
    }
    if (res.size() == 0)
        if (n == 1)
            cout << "There is " << n << " account and no account is modified"
                 << endl;
        else
            cout << "There are " << n << " accounts and no account is modified"
                 << endl;
    else {
        cout << res.size() << endl;
        for (auto it : res) cout << it.name << " " << it.password << endl;
    }

    return 0;
}