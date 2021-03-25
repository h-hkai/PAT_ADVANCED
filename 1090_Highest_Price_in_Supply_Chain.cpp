#include<iostream>
#include<map>
#include<iomanip>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int n;
    double p, r;
    cin >> n >> p >> r;

    int t;
    vector<int> chain(n);
    for (int i = 0; i < n; ++i) {
        cin >> t;
        chain[i] = t;
    }
    map<int, vector<int> > mp;
    int last;
    for (int i = 0; i < n; ++i) {
        last = chain[i];
        mp[last].push_back(i);
    }

    auto it = mp.find(-1);
    vector<int> v = it->second;
    queue<int> q;
    for (int i = 0; i < v.size(); ++i)
        q.push(v[i]);
    q.push(-1);
    int len = 0, num = 0;
    while(!q.empty()) {
        if (q.size() == 1) break;
        int f = q.front();
        q.pop();
        num++;
        if (f == -1) {
            len++;
            num = 0;
            q.push(-1);
        } else {
            if (mp.find(f) != mp.end()) {
                v = mp.find(f)->second;
                for (int i = 0; i < v.size(); ++i)
                    q.push(v[i]);
            }
        }
    }

    double heighPrice = p;
    for (int i = 0; i < len; ++i) {
        heighPrice *= (1 + r/100);
    }

    cout << fixed << setprecision(2) << heighPrice << " " << num << endl;
    
    return 0;
}