#include <bits/stdc++.h>

using namespace std;

typedef struct Student* student;

struct Student {
    string Id;
    int Gp;
    int Gm;
    int Gf;
    int final;
    Student(string id) {
        Id = id;
        Gp = -1;
        Gm = -1;
        Gf = -1;
    }
};

bool cmp(student a, student b) {
    if (a->final != b->final)
        return a->final > b->final;
    else
        return a->Id < b->Id;
}

int main() {
    int P, M, N, score;
    string id;
    cin >> P >> M >> N;
    map<string, student> mp;
    for (int i = 0; i < P; ++i) {
        cin >> id >> score;
        if (score < 200) continue;
        student stu = new Student(id);
        stu->Gp = score;
        mp[id] = stu;
    }
    for (int i = 0; i < M; ++i) {
        cin >> id >> score;
        if (mp.find(id) != mp.end()) {
            mp[id]->Gm = score;
        }
    }
    for (int i = 0; i < N; ++i) {
        cin >> id >> score;
        if (mp.find(id) != mp.end()) {
            mp[id]->Gf = score;
            int final = score > mp[id]->Gm
                            ? score
                            : (mp[id]->Gm * 0.4 + score * 0.6 + 0.5);
            mp[id]->final = final;
        }
    }
    vector<student> stu;
    for (auto it : mp) {
        if (it.second->final >= 60 && it.second->final <= 100)
            stu.push_back(it.second);
    }
    sort(stu.begin(), stu.end(), cmp);

    for (int i = 0; i < stu.size(); ++i) {
        cout << stu[i]->Id << " " << stu[i]->Gp << " " << stu[i]->Gm << " "
             << stu[i]->Gf << " " << stu[i]->final << endl;
    }

    return 0;
}