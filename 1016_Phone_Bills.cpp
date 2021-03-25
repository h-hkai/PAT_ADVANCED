#include <bits/stdc++.h>

using namespace std;

vector<int> costs(24);
int costOfDay;

struct People {
    string name;
    vector<string> on_line;
    vector<string> off_line;
};

bool cmp1(People a, People b) { return a.name < b.name; }
bool cmp2(string s1, string s2) { return s1 < s2; }

pair<int, double> parse(string str1, string str2) {
    int day1 = stoi(str1.substr(3, 2));
    int day2 = stoi(str2.substr(3, 2));
    pair<int, int> time1 = {stoi(str1.substr(6, 2)), stoi(str1.substr(9, 2))};
    pair<int, int> time2 = {stoi(str2.substr(6, 2)), stoi(str2.substr(9, 2))};
    int numOfDays = 0;
    if (time1.first * 60 + time1.second < time2.first * 60 + time2.second) {
        numOfDays = day2 - day1;
    } else {
        numOfDays = day2 - day1 - 1;
    }
    double cost = 0.0;
    int totalMinute = 0;
    if (time1.first == time2.first) {
        cost += (time2.second - time1.second) * costs[time1.first];
        totalMinute += time2.second - time1.second;
    } else {
        cost += (60 - time1.second) * costs[time1.first] +
                time2.second * costs[time2.first];
        totalMinute += 60 - time1.second + time2.second;
        for (int i = time1.first + 1; i < time2.first; ++i) {
            cost += 60 * costs[i];
            totalMinute += 60;
        }
    }
    totalMinute += numOfDays * 24 * 60;
    cost += numOfDays * costOfDay;
    double dollar = cost / 100.0;
    return {totalMinute, dollar};
}

int main() {
    for (int i = 0; i < 24; ++i) {
        cin >> costs[i];
        costOfDay += costs[i] * 60;
    }
    int N;
    cin >> N;
    getchar();
    string record;
    map<string, People> m;
    for (int i = 0; i < N; ++i) {
        getline(cin, record);
        int space1, space2;
        space1 = record.find(' ');
        space2 = record.find(' ', space1 + 1);
        string name = record.substr(0, space1);
        string date = record.substr(space1 + 1, space2 - space1 - 1);
        string status = record.substr(space2 + 1);
        if (status == "on-line") {
            m[name].on_line.push_back(date);
        } else {
            m[name].off_line.push_back(date);
        }
    }
    vector<People> peoples;
    for (auto it : m) {
        it.second.name = it.first;
        peoples.push_back(it.second);
    }
    sort(peoples.begin(), peoples.end(), cmp1);
    for (People p : peoples) {
        sort(p.on_line.begin(), p.on_line.end(), cmp2);
        sort(p.off_line.begin(), p.off_line.end(), cmp2);
        vector<string> start, end;
        int index = 0, len1 = p.on_line.size(), len2 = p.off_line.size();
        for (int i = 0; i < len2 && index < len1; ++i) {
            while (index < len1 && p.on_line[index] < p.off_line[i]) index++;
            if (index > 0) {
                start.push_back(p.on_line[index - 1]);
                end.push_back(p.off_line[i]);
            }
        }
        cout << p.name << " " << start[0].substr(0, 2) << endl;
        double totalCost = 0.0;
        for (int i = 0; i < start.size(); ++i) {
            cout << start[i].substr(3) << " " << end[i].substr(3) << " ";
            pair<int, double> ans = parse(start[i], end[i]);
            totalCost += ans.second;
            cout << ans.first << " $" << fixed << setprecision(2) << ans.second
                 << endl;
        }
        cout << "Total amount: $" << totalCost << endl;
    }

    return 0;
}