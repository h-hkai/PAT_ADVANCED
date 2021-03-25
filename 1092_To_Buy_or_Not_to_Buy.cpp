#include<iostream>
#include<map>

using namespace std;

int main() {
    string shopOwer, Eva;
    cin >> shopOwer >> Eva;

    map<char, int> m;

    for (int i = 0; i < shopOwer.length(); ++i) {
        m[shopOwer[i]] += 1;
    }
    int lose = 0;
    for (int i = 0; i < Eva.length(); ++i) {
        if (m[Eva[i]] == 0) lose++;
        else m[Eva[i]]--;
    }

    if (lose > 0) {
        cout << "No" << " " << lose << endl;
    } else {
        cout << "Yes" << " " << shopOwer.length()-Eva.length() << endl;
    }

    return 0;
}