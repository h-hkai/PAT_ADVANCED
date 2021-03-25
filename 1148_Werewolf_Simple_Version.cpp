#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    int n, t;
    cin >> n;

    set<int> human;
    set<int> werewolf;
    vector<int> said(n+1, 0);
    vector<pair<int, int> > twoWereWolf;

    for (int i = 1; i <= n; ++i) {
        cin >> t;
        said[i] = t;
    }

    bool wrong = false;
    int werewolf1, werewolf2;
    bool foundWerewolf1 = false;
    bool foundWerewolf2 = false;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j == i) continue;
            werewolf1 = -1;
            werewolf2 = -1;
            wrong = false;
            foundWerewolf1 = false;
            foundWerewolf2 = false;
            human.clear();
            werewolf.clear();
            for (int k = 1; k <= n; ++k) {
                if (k != i && k != j) {
                    if (said[k] < 0)
                        werewolf.insert(abs(said[k]));
                    else 
                        human.insert(said[k]);
                }
            }
            for (int h : human) {
                if (h == i) {
                    werewolf1 = j;
                    foundWerewolf1 = true;
                }
                if (h == j) {
                    werewolf1 = i;
                    foundWerewolf1 = true;
                }
            }
            for (int w : werewolf) {
                if (w != werewolf1) {
                    werewolf2 = w;
                    foundWerewolf2 = true;
                }
            }
            if (foundWerewolf1 && foundWerewolf2) {
                if (human.find(foundWerewolf1) == human.end() && human.find(foundWerewolf2) == human.end())
                    twoWereWolf.push_back({werewolf1, werewolf2});
            }
        }
    }

    sort(twoWereWolf.begin(), twoWereWolf.end(), cmp);

    if (twoWereWolf.size() > 0) {
        cout << twoWereWolf[0].first << " " << twoWereWolf[0].second << endl;
    } else {
        cout << "No Solution" << endl;
    }

    return 0;
}