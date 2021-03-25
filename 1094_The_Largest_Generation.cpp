#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<int, vector<int> > mp;
    vector<int> son;
    for (int i = 0; i < m; ++i) {
        int f, cnt, s;
        cin >> f >> cnt;
        for (int j = 0; j < cnt; ++j) {
            cin >> s;
            son.push_back(s);
        }
        mp[f] = son;
        son.clear();
    }

    int count = 1, level = 1;
    int temp1 = 0, temp2 = 1;
    queue<int> q;
    q.push(1);
    q.push(0);
    while (q.size() > 1) {
        int f = q.front();
        q.pop();
        if (f == 0) {
            q.push(0);
            temp2 += 1;
            level = temp1 > count ? temp2 : level;
            count = temp1 > count ? temp1 : count;
            temp1 = 0;
        }
        if (mp.find(f) != mp.end()) {
            son = mp.find(f)->second;
            for (int i = 0; i < son.size(); ++i) {
                q.push(son[i]);
            }
            temp1 += son.size();
        }
            
    }

    cout << count << " " << level << endl;

    return 0;
}