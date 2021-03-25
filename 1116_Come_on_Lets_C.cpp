#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, k;
    cin >> n;
    string id;
    map<string, int> list;
    for (int i = 1; i <= n; ++i) {
        cin >> id;
        list.insert({id, i});
    }
    cin >> k;
    set<string> visited;
    for (int i = 0; i < k; ++i) {
        cin >> id;
        if (list.find(id) == list.end()) {
            cout << id << ": Are you kidding?" << endl;
        } else if (visited.find(id) != visited.end()) {
            cout << id << ": Checked" << endl;
        } else if (list[id] == 1) {
            cout << id << ": Mystery Award" << endl;
        } else if (isPrime(list[id])) {
            cout << id << ": Minion" << endl;
        } else {
            cout << id << ": Chocolate" << endl;
        }
        visited.insert(id);
    }

    return 0;
}