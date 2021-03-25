#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> order(55, 0);
    vector<int> start(55, 0);
    vector<int> end(55, 0);
    for (int i = 1; i <= 54; ++i) {
        cin >> order[i];
        end[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        start = end;
        for (int j = 1; j <= 54; ++j) {
            end[order[j]] = start[j];
        }
    }
    vector<char> ch = {'S', 'H', 'C', 'D'};
    vector<string> cards;
    cards.push_back("start");
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j < 14; ++j) {
            string temp = ch[i] + to_string(j);
            cards.push_back(temp);
        }
    }
    cards.push_back("J1");
    cards.push_back("J2");
    for (int i = 1; i <= 54; ++i)
        if (i == 1)
            cout << cards[end[i]];
        else
            cout << " " << cards[end[i]];
    cout << endl;
    return 0;
}