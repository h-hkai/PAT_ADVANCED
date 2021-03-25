#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;

int main() {
    string origianl, test;
    cin >> origianl >> test;
    map<char, int> m;
    set<int> visited;
    char c;
    for (int i = 0; i < origianl.length(); ++i) {
        c = origianl[i];
        m[toupper(c)]++;
    }
    for (int i = 0; i < test.length(); ++i) {
        c = test[i];
        m[toupper(c)]--;
    }
    for(int i = 0; i < origianl.length(); ++i) {
        c = toupper(origianl[i]);
        if (m[c] > 0 && visited.find(c) == visited.end()) {
            cout << c;
            visited.insert(c);
        }
    }

    return 0;
}