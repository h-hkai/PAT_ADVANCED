#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
#include<cstdio>

using namespace std;

struct Info {
    char level;
    string site;
    string date;
    string testee;
    int sorce;
    string cardNumber;
};

bool cmp1(Info a, Info b) {
    if (a.sorce == b.sorce)
        return a.cardNumber < b.cardNumber;
    return a.sorce > b.sorce;
}

bool cmp2(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) 
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    string info;
    int sorce;
    Info submit;
    vector<Info> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> info >> sorce;
        v[i].level = info[0];
        v[i].site = info.substr(1, 3);
        v[i].date = info.substr(4, 6);
        v[i].testee = info.substr(10, 3);
        v[i].sorce = sorce;
        v[i].cardNumber = info;
    }

    getchar();
    string Case;
    for (int i = 1; i <= m; ++i) {
        getline(cin, Case);
        int Type = Case[0] - '0';
        string Term = Case.substr(2);
        switch (Type) {
        case 1: {
            cout << "Case " << i << ": " << Case << endl;
            char l = Term[0];
            sort(v.begin(), v.end(), cmp1);
            if (v.size() == 0) {
                cout << "NA" << endl;
            } else {
                for (int i = 0; i < v.size(); ++i) {
                    if (v[i].level == l) {
                        cout << v[i].cardNumber << " " << v[i].sorce << endl;
                    }
                }
            }

            break;
        }
        case 2: {
            int Nt = 0, Ns = 0;
            cout << "Case " << i << ": " << Case << endl;
            for (int i = 0; i < v.size(); ++i) {
                if (v[i].site == Term) {
                    Nt++;
                    Ns += v[i].sorce;
                }
            }
            if (Nt == 0) {
                cout << "NA" << endl;
            } else {
                cout << Nt << " " << Ns << endl;
            }
            
            break;
        }
        case 3: {
            cout << "Case " << i << ": " << Case << endl;
            unordered_map<string, int> mp;
            for (int i = 0; i < v.size(); ++i) {
                if (v[i].date == Term) {
                    mp[v[i].site]++;
                }
            }
            vector<pair<string, int> > temp;
            for (auto it = mp.begin(); it != mp.end(); ++it) {
                temp.push_back({it->first, it->second});
            }
            sort(temp.begin(), temp.end(), cmp2);
            if (temp.size() == 0) { 
                cout << "NA" << endl;
            } else {
                for (int i = 0; i < temp.size(); ++i) {
                    cout << temp[i].first << " " << temp[i].second << endl;
                }
            }

            break;
        }
        
        default:
            break;
        }
    }


    return 0;
}