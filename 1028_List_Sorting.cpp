#include <bits/stdc++.h>

using namespace std;

struct Stu {
    int id;
    char name[10];
    int grade;
} students[100005];

bool cmp1(Stu a, Stu b) { return a.id < b.id; }
bool cmp2(Stu a, Stu b) { return strcmp(a.name, b.name) <= 0; }
bool cmp3(Stu a, Stu b) { return a.grade <= b.grade; }

int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i)
        scanf("%d%s%d", &students[i].id, students[i].name, &students[i].grade);
    if (c == 1)
        sort(students, students + n, cmp1);
    else if (c == 2)
        sort(students, students + n, cmp2);
    else
        sort(students, students + n, cmp3);
    for (int i = 0; i < n; ++i)
        cout << setw(6) << setfill('0') << students[i].id << " "
             << students[i].name << " " << students[i].grade << endl;
    return 0;
}