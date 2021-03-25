#include <bits/stdc++.h>

using namespace std;

struct Stu {
    string name;
    char gender;
    string id;
    int grade;
};

bool cmp1(Stu s1, Stu s2) { return s1.grade < s2.grade; }

bool cmp2(Stu s1, Stu s2) { return s1.grade > s2.grade; }

int main() {
    int n;
    cin >> n;
    vector<Stu> male, female;
    for (int i = 0; i < n; ++i) {
        string name, id;
        char gender;
        int grade;
        cin >> name >> gender >> id >> grade;
        if (gender == 'F')
            female.push_back({name, gender, id, grade});
        else
            male.push_back({name, gender, id, grade});
    }
    sort(female.begin(), female.end(), cmp2);
    sort(male.begin(), male.end(), cmp1);
    if (female.size() > 0)
        cout << female[0].name << " " << female[0].id << endl;
    else
        cout << "Absent" << endl;
    if (male.size() > 0)
        cout << male[0].name << " " << male[0].id << endl;
    else
        cout << "Absent" << endl;
    if (female.size() > 0 && male.size() > 0)
        cout << female[0].grade - male[0].grade << endl;
    else
        cout << "NA" << endl;
    return 0;
}