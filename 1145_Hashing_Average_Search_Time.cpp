#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int getPos(int key, int d, int MSize) { return (key + d * d) % MSize; }

int main() {
    int MSize, N, M;
    cin >> MSize >> N >> M;

    while (!isPrime(MSize)) MSize++;
    vector<int> v(MSize, 0);

    int key;
    bool found;
    for (int i = 0; i < N; ++i) {
        cin >> key;
        found = false;
        for (int j = 0; j < MSize; ++j) {
            int pos = getPos(key, j, MSize);
            if (v[pos] == 0) {
                v[pos] = key;
                found = true;
                break;
            }
        }
        if (!found) cout << key << " cannot be inserted." << endl;
    }

    int step = 0;
    for (int i = 0; i < M; ++i) {
        int query;
        cin >> query;
        for (int j = 0; j <= MSize; ++j) {
            step++;
            int pos = getPos(query, j, MSize);
            if (v[pos] == query || v[pos] == 0) break;
        }
    }

    cout << setiosflags(ios::fixed) << setprecision(1) << step * 1.0 / M
         << endl;

    return 0;
}