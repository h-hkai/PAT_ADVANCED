#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#include<climits>

using namespace std;

typedef struct Customer {
    int num;
    int startTime;
    int doneTime;
}cus;

int main() {
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    vector<queue<cus>> v(N);
    vector<int> time(N, 0);
    map<int, cus> m;

    int i, t, j = 1, flag = 0;
    for (i = 0; i < N*M; ++i) {
        cin >> t;
        v[i%N].push({i+1, time[i%N], time[i%N]+t});
        m.insert({i+1, {i+1, time[i%N], time[i%N]+t}});
        time[i%N] += t;
    }
    for (; i < K; ++i) {
        cin >> t;
        flag = 0;

        int endTime = INT_MAX, tag;
        for (int k = 0; k < N; ++k) {
            if (v[k].size() < M && v[k].front().doneTime < endTime) {
                tag = k;
                flag = 1;
            }
        }

        if (flag) {
            v[tag].push({i+1, time[tag], time[tag]+t});
            m.insert({i+1,{i+1, time[tag], time[tag]+t}});
            time[tag] += t;
            continue;
        }

        for (; j < 541; ++j) {
            for (int k = 0; k < N; ++k) {
                if (v[k].front().doneTime == j) {
                    v[k].pop();
                    v[k].push({i+1, time[k], time[k]+t});
                    m.insert({i+1,{i+1, time[k], time[k]+t}});
                    time[k] += t;
                    flag = 1;
                }
            }
            if (flag) { --j; break; }
        }
    }

    for (int i = 0; i < Q; ++i) {
        cin >> t;
        int mins, hours;
        mins = m[t].doneTime % 60;
        hours = m[t].doneTime / 60;
        if (m[t].startTime >= 540) cout << "Sorry" << endl;
        else cout << setfill('0') << setw(2) << 8+hours << ":" << setfill('0') << setw(2) << mins << endl;
    }

    return 0;
}