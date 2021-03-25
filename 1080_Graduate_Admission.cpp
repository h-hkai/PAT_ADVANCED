#include <bits/stdc++.h>

using namespace std;

struct Student {
    int id;
    int Ge;
    int Gi;
    int fianl;
    int rank;
    vector<int> choices;
};

bool cmp1(Student& a, Student& b) {
    if (a.fianl == b.fianl)
        return a.Ge > b.Ge;
    else
        return a.fianl > b.fianl;
}

bool cmp2(Student& a, Student& b) { return a.id < b.id; }

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<Student> stu, sch[105];
    vector<int> quota(m), count(m, 0);
    for (int i = 0; i < m; ++i) cin >> quota[i];
    for (int i = 0; i < n; ++i) {
        int Ge, Gi;
        cin >> Ge >> Gi;
        vector<int> choices(k);
        for (int j = 0; j < k; ++j) cin >> choices[j];
        int final = Ge + Gi;
        stu.push_back({i, Ge, Gi, final, 0, choices});
    }
    sort(stu.begin(), stu.end(), cmp1);
    stu[0].rank = 1;
    for (int i = 1; i < n; ++i) {
        if (stu[i].fianl == stu[i - 1].fianl && stu[i].Ge == stu[i - 1].Ge)
            stu[i].rank = stu[i - 1].rank;
        else {
            stu[i].rank = stu[i - 1].rank + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int schid = stu[i].choices[j];
            int lastid = count[schid] - 1;
            if (quota[schid] > count[schid] ||
                sch[schid][lastid].rank == stu[i].rank) {
                sch[schid].push_back(stu[i]);
                count[schid]++;
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        sort(sch[i].begin(), sch[i].end(), cmp2);
        for (int j = 0; j < sch[i].size(); ++j) {
            if (j == 0)
                cout << sch[i][j].id;
            else
                cout << " " << sch[i][j].id;
        }
        cout << endl;
    }

    return 0;
}