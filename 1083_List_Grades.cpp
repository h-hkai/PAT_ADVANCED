#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    string id;
    int grade;
};

bool cmp(Student a, Student b) { return a.grade > b.grade; }

int main() {
    int n;
    cin >> n;
    vector<Student> v;
    for (int i = 0; i < n; ++i) {
        string name, id;
        int grade;
        cin >> name >> id >> grade;
        v.push_back({name, id, grade});
    }
    int grade1, grade2;
    cin >> grade1 >> grade2;
    bool found = false;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; ++i)
        if (v[i].grade >= grade1 && v[i].grade <= grade2) {
            found = true;
            cout << v[i].name << " " << v[i].id << endl;
        }
    if (!found) cout << "NONE" << endl;

    return 0;
}