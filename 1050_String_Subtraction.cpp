#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    unordered_set<char> visited;
    for (int i = 0; i < s2.length(); ++i) visited.insert(s2[i]);
    string ans = "";
    for (int i = 0; i < s1.length(); ++i)
        if (visited.find(s1[i]) == visited.end()) ans += s1[i];
    cout << ans << endl;
    return 0;
}