#include <bits/stdc++.h>

using namespace std;

struct People {
    string id;
    int virtue_grade;
    int talent_grade;
    int total_grade;

    bool operator<(const People& b) {
        if (total_grade != b.total_grade) return total_grade > b.total_grade;
        if (virtue_grade != b.virtue_grade)
            return virtue_grade > b.virtue_grade;
        else
            return id < b.id;
    }
};

int main() {
    int n, l, h, total = 0;
    cin >> n >> l >> h;
    vector<People> sages, nobleman, foolman, smallman;
    for (int i = 0; i < n; ++i) {
        string id;
        int virtue_grade, talent_grade, total_grade;
        cin >> id >> virtue_grade >> talent_grade;
        if (virtue_grade >= l and talent_grade >= l) {
            total++;
            total_grade = virtue_grade + talent_grade;
            People temp{id, virtue_grade, talent_grade, total_grade};
            if (virtue_grade >= h && talent_grade >= h)
                sages.push_back(temp);
            else if (virtue_grade >= h)
                nobleman.push_back(temp);
            else if (virtue_grade >= talent_grade)
                foolman.push_back(temp);
            else
                smallman.push_back(temp);
        }
    }
    cout << total << endl;
    sort(sages.begin(), sages.end());
    for (int i = 0; i < sages.size(); ++i)
        cout << sages[i].id << " " << sages[i].virtue_grade << " "
             << sages[i].talent_grade << endl;
    sort(nobleman.begin(), nobleman.end());
    for (int i = 0; i < nobleman.size(); ++i)
        cout << nobleman[i].id << " " << nobleman[i].virtue_grade << " "
             << nobleman[i].talent_grade << endl;
    sort(foolman.begin(), foolman.end());
    for (int i = 0; i < foolman.size(); ++i)
        cout << foolman[i].id << " " << foolman[i].virtue_grade << " "
             << foolman[i].talent_grade << endl;
    sort(smallman.begin(), smallman.end());
    for (int i = 0; i < smallman.size(); ++i)
        cout << smallman[i].id << " " << smallman[i].virtue_grade << " "
             << smallman[i].talent_grade << endl;

    return 0;
}