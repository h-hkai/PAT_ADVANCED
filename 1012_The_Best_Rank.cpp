#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

typedef struct Student {
    string num;
    int C;
    int M;
    int E;
    int A;
    int rankOfC;
    int rankOfM;
    int rankOfE;
    int rankOfA;
    vector<pair<char, int>> inRank;
}student;

vector<student> s;

bool CmpOfC(student x, student y) {
    return x.C > y.C;
}

bool CmpOfM(student x, student y) {
    return x.M > y.M;
}

bool CmpOfE(student x, student y) {
    return x.E > y.E;
}

bool CmpOfA(student x, student y) {
    return x.A > y.A;
}

bool CmpOfInRank(pair<char, int> x, pair<char, int> y) {
    if (x.second == y.second) {
        if (x.first == 'E' && y.first == 'M' ||
            x.first == 'M' && y.first == 'E')
            return x.first > y.first;
        else 
            return x.first < y.first;
    } else {
        return x.second < y.second;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string id;
        int c, m, e, a;
        cin >> id >> c >> m >> e;
        a = (c + m + e) / 3.0 + 0.5;
        student S = {id, c, m, e, a};
        s.push_back(S);
    }

    sort(s.begin(), s.end(), CmpOfC);
    s[0].rankOfC = 1;
    s[0].inRank.push_back({'C', 1});
    int indexOfC = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i].C == s[i-1].C) s[i].rankOfC = indexOfC;
        else s[i].rankOfC = ++indexOfC;
        s[i].inRank.push_back({'C', indexOfC});
    }

    sort(s.begin(), s.end(), CmpOfM);
    s[0].rankOfM = 1;
    s[0].inRank.push_back({'M', 1});
    int indexOfM = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i].M == s[i-1].M) s[i].rankOfM = indexOfM;
        else s[i].rankOfM = ++indexOfM;
        s[i].inRank.push_back({'M', indexOfM});
    }

    sort(s.begin(), s.end(), CmpOfE);
    s[0].rankOfE = 1;
    s[0].inRank.push_back({'E', 1});
    int indexOfE = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i].E == s[i-1].E) s[i].rankOfE = indexOfE;
        else s[i].rankOfE = ++indexOfE;
        s[i].inRank.push_back({'E', indexOfE});
    }

    sort(s.begin(), s.end(), CmpOfA);
    s[0].rankOfA = 1;
    s[0].inRank.push_back({'A', 1});
    int indexOfA = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i].A == s[i-1].A) s[i].rankOfA = indexOfA;
        else s[i].rankOfA = ++indexOfA;
        s[i].inRank.push_back({'A', indexOfA});
    }

    map<string, student> M;

    for (int i = 0; i < s.size(); ++i) {
        M.insert({s[i].num, s[i]});
    }

    for (int i = 0; i < m; ++i) {
        string id;
        cin >> id;
        if (M.find(id) != M.end()) {
            sort(M.find(id)->second.inRank.begin(), M.find(id)->second.inRank.end(), CmpOfInRank);
            cout << M.find(id)->second.inRank[0].second << " " << M.find(id)->second.inRank[0].first << endl;
        } else {
            cout << "N/A" << endl;
        }
    }

    return 0;
}