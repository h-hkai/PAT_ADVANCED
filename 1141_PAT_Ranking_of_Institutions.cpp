#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct School {
    int Rank;
    string school;
    double TWS;
    int Ns;
};

bool cmp(School s1, School s2) {
    if (s1.TWS != s2.TWS)
        return s1.TWS > s2.TWS;
    else if (s1.Ns != s2.Ns)
        return s1.school < s2.school;
    else
        return s1.Ns < s2.Ns;
}

string toLower(string str) {
    for (int i = 0; i < str.length(); ++i) str[i] = tolower(str[i]);
    return str;
}

int main() {
    int n;
    cin >> n;
    getchar();
    string inf;
    map<string, School> m;
    map<char, double> s;
    s['B'] = 0.66666667;
    s['A'] = 1.0;
    s['T'] = 1.5;
    for (int i = 0; i < n; ++i) {
        getline(cin, inf);
        string ID = inf.substr(0, 6);
        int pos = 7;
        while (inf[pos] != ' ') pos++;
        int score = stoi(inf.substr(7, pos - 7));
        string school = toLower(inf.substr(pos + 1));
        m[school].school = school;
        m[school].TWS += score * s[ID[0]];
        m[school].Ns += 1;
    }
    vector<School> v;
    for (auto it : m) {
        it.second.TWS = (int)it.second.TWS;
        v.push_back(it.second);
    }
    sort(v.begin(), v.end(), cmp);
    int rank = 1;
    v[0].Rank = rank;
    for (int i = 1; i < v.size(); ++i) {
        rank++;
        if (v[i].TWS == v[i - 1].TWS)
            v[i].Rank = v[i - 1].Rank;
        else
            v[i].Rank = rank;
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].Rank << " " << v[i].school << " " << v[i].TWS << " "
             << v[i].Ns << endl;
    }
    return 0;
}