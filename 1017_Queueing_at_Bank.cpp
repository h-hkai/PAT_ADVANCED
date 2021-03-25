#include <bits/stdc++.h>

using namespace std;

const int inf = 0x7fffffff;

struct People {
    int arraving_time;
    int processing_time;
};

bool cmp(People a, People b) { return a.arraving_time < b.arraving_time; }

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int hh, mm, ss, t;
    vector<People> peoples(N);
    vector<int> windows(K, 8 * 3600);
    for (int i = 0; i < N; ++i) {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &t);
        peoples[i].arraving_time = hh * 3600 + mm * 60 + ss;
        peoples[i].processing_time = t * 60;
    }
    sort(peoples.begin(), peoples.end(), cmp);
    int count = 0;
    double waiting_time = 0.0;
    for (int i = 0; i < N; ++i) {
        if (peoples[i].arraving_time > 17 * 3600) break;
        int strating_time = inf, index;
        for (int j = 0; j < K; ++j) {
            if (strating_time > windows[j]) {
                index = j;
                strating_time = windows[j];
            }
        }
        count++;
        if (strating_time > peoples[i].arraving_time) {
            waiting_time += strating_time - peoples[i].arraving_time;
            windows[index] = strating_time + peoples[i].processing_time;
        } else {
            windows[index] =
                peoples[i].arraving_time + peoples[i].processing_time;
        }
    }
    printf("%.01f\n", waiting_time / (60 * count));
    return 0;
}