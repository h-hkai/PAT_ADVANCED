#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<stdio.h>

using namespace std;

struct Record {
    string plate_name;
    int time;
    string status;
    Record(string s1, int t, string s2): plate_name(s1), time(t), status(s2) {}
};

struct Plate {
    string name;
    int num = 0;
    int period = 0;
    int startTime = 0;
};

bool cmp1(Record a, Record b) {
    return a.time < b.time;
}

bool cmp2(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first;
}

int toSecond(string time) {
    string hh, mm, ss;
    hh = time.substr(0, 2);
    mm = time.substr(3, 2);
    ss = time.substr(6, 2);
    return stoi(hh)*60*60 + stoi(mm)*60 + stoi(ss);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<Record> v;
    map<string, Plate> mp;
    string plate_name, time, status;
    for (int i = 0; i < n; ++i) {
        cin >> plate_name >> time >> status;
        int sec = toSecond(time);
        if (mp.find(plate_name) == mp.end()) mp[plate_name] = {plate_name, 0, 0, 0};
        Record r = Record(plate_name, sec, status);
        v.push_back(r);
    }
    sort(v.begin(), v.end(), cmp1);
    int len = v.size();
    vector<pair<int, int> > per;
    for (int i = 0; i < len; ++i) {
        string name = v[i].plate_name;
        if (v[i].status == "in") {
            if (mp[name].num > 0) {
                mp[name].startTime = v[i].time;
            } else {
                mp[name].num = 1;
                mp[name].startTime = v[i].time;
            }
        } else {
            if (mp[name].num > 0) {
                mp[name].num = 0;
                mp[name].period += v[i].time - mp[name].startTime;
                per.push_back({mp[name].startTime, v[i].time});
            } else {
                continue;
            }
        }
    }

    int count;
    for (int i = 0; i < m; ++i) {
        string query;
        cin >> query;
        count = 0;
        int t = toSecond(query);
        for (int j = 0; j < per.size(); ++j) {
            if (t < per[j].second && t >= per[j].first) count++;
        }
        printf("%d\n", count);
    }

    vector<pair<int, string> > v2;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        int per = it->second.period;
        string str = it->second.name;
        v2.push_back({per, str});
    }
    
    sort(v2.begin(), v2.end(), cmp2);

    printf("%s ", v2[0].second.c_str());
    for (int i = 1; i < v2.size(); ++i) {
        if (v2[i].first == v2[i-1].first)
            printf("%s ", v2[i].second.c_str());
    }
    int max_time = v2[0].first;
    int hh = max_time / 3600;
    int mm = (max_time % 3600) / 60;
    int ss = (max_time % 3600) % 60;

    printf("%02d:%02d:%02d\n", hh, mm, ss);

    return 0;
}
